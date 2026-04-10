#include "ECS_obj.h"
#include <raymath.h>
#include "useful_functions.h"
#include "physics_system.h"

Vector2 univ_grav(float m1, float m2, Vector2 pos1, Vector2 pos2) { // returns gravity force vector from m1 to m2
	float gravity_scalar;
	Vector2 relative_position;
	float distance;
	Vector2 norm_rel_position; // unit vector pointing from m1 to m2
	Vector2 gravity_force_vector;


	relative_position = pos1 - pos2;
	distance = Vector2Length(relative_position) + 50.0f; // +50.0f prevents div by 0 singularity since magnitudes are positive
	norm_rel_position = relative_position / distance; // initialized unit vector from m1 to m2

	gravity_scalar = -1 * G * m1 * m2;

	gravity_force_vector = norm_rel_position * gravity_scalar / (distance * distance);

	return gravity_force_vector;

};

float moment_of_inertia(float mass_of_each_point, std::vector<Vector2> points) { // for uniform point masses, assuming points are relative to COM
	float moment{};

	Vector2 center_of_points{}; // we can subtract this from each element in points to move to {0,0}

	for (int i = 0; i < std::size(points); i++) {
		moment += mass_of_each_point * Vector2LengthSqr(points[i] - center_of_points);
	};

	return moment;
};

float num_deriv_backwards(float first_value, float second_value) { // returns average rate of change over time interval dt
	// uses backwards derivative method, first order error
	return (second_value - first_value) / dt;

};

float num_deriv_array_backwards(std::vector<float> vals_to_diff) { // works like num_deriv but accepts std::vector<float> type
	float val1 = vals_to_diff.at(0);
	float val2 = vals_to_diff.at(1);

	return num_deriv_backwards(val1, val2);
};

float num_deriv_centered(float x_t_pls_1, float x_t_min_1) { // returns average rate of change over time interval dt 
	// uses centered derivative method, second order error, see ideas.txt
	return (x_t_pls_1 - x_t_min_1) / (2 * dt);

};

float num_deriv_array_centered(std::vector<float> vals_to_diff) { // works like num_deriv but accepts std::vector<float> type
	// takes array with 3 elements
	float val1 = vals_to_diff.at(0);
	float val2 = vals_to_diff.at(2);

	return num_deriv_centered(val1, val2);
};

Vector2 return_rel_vel(int ID1, int ID2) { // returns difference of velocities between two entities with ID = ID1, ID2
	// does not account for relativity
	// ...
	// YET! 
	// god help me if I ever get sucked into making this use relativity
	// honestly it would be best to start over if I do that

	Vector2 vel1 = ECS_obj.get_entity_components(ID1).m_velocity;

	Vector2 vel2 = ECS_obj.get_entity_components(ID2).m_velocity;

	return Vector2Subtract(vel2, vel1);

};

float angle_of_vec_diff(Vector2 vec1, Vector2 vec2) { // returns angle of vector difference of vec1 and vec2
	Vector2 vec_res{ vec1 - vec2 };

	float angle_diff = clamp_angle(atan2(vec_res.y, vec_res.x) + PI ); // the PI is needed due to left handed coordinate system

	return angle_diff;

};

float angle_of_vec_diff_unclamped(Vector2 vec1, Vector2 vec2) { // returns angle of vector difference of vec1 and vec2, does not use clamp
	// (see useful_functions.cpp)
	Vector2 vec_res{ vec2 - vec1 };

	float angle_output = atan2(vec_res.y, vec_res.x);

	if (angle_output < PI) {

		return angle_output;

	}
	else {

		return 2 * PI - angle_output;
	
	};
};

float minimum_angle(float input_angle) { // returns abs_val minimum of input_angle and 2 * PI - input_angle

	if (abs(input_angle) <= 2 * PI - abs(input_angle)) {
		return input_angle;
	}
	else {
		return 2 * PI - input_angle;
	};


};

float better_sign_function(float x) {
	x = 2 * std::signbit(x) - 1;
	return x;
};

float return_accel_propnav(int N, float lambda_dot, float closing_velocity) { // Uses 2D proportional navigation equation
	// N is a number between 3-5, lambda_dot is the R.O.C. of the Line of Sight angle, and closing velocity is just
	// relative velocity
	return N * lambda_dot * closing_velocity;
};

float return_LOS_angle(int ID) { // returns Line of Sight (LOS) angle between an entity with an ID and its target
	// mathematically, compares the angle of the vector difference of the positions of two entities to the angle of the targeting entity
	int target_ID = ECS_obj.get_entity_components(ID).m_target_id;

	Vector2 pos1 = ECS_obj.get_entity_components(ID).m_position;
	Vector2 pos2 = ECS_obj.get_entity_components(target_ID).m_position;

	float system_angle = ECS_obj.get_entity_components(ID).m_angle;

	Vector2 pointing_vector = { cos(system_angle), sin(system_angle) };
	
	Vector2 diff_positional_vector = Vector2Normalize(Vector2Subtract(pos2, pos1));

	return Vector2Angle(pointing_vector, diff_positional_vector);
};

void physics_update(int ID) { // updates physics components when called
	// updating physics components via kinematic equations
	// this cascades changes in the force/torque component to the accel, vel, and pos (and angular versions) components
	// to move physics objects, just change the force/torque component of a given entity ID
	// and call this system to move it around :)

	ECS_obj.get_entity_components(ID);

	if (ECS_obj.get_entity_components(ID).m_name != "Planetoid") {
		// initializing variables

		float mass{ ECS_obj.get_entity_components(ID).m_mass };

		Vector2 position{ ECS_obj.get_entity_components(ID).m_position };

		Vector2 velocity{ ECS_obj.get_entity_components(ID).m_velocity };

		Vector2 acceleration{ ECS_obj.get_entity_components(ID).m_acceleration };

		Vector2 force{ ECS_obj.get_entity_components(ID).m_force };

		std::vector<Vector2> shape{ ECS_obj.get_entity_components(ID).m_shape };

		float moment{ moment_of_inertia(mass, shape) }; // moment of inertia used for torque stuff, not an ECS param

		float angle{ ECS_obj.get_entity_components(ID).m_angle };

		float angvel{ ECS_obj.get_entity_components(ID).m_angvel };

		float angacc{ ECS_obj.get_entity_components(ID).m_angacc };

		float torque{ ECS_obj.get_entity_components(ID).m_torque };

		int target_ID{ ECS_obj.get_entity_components(ID).m_target_id };

		bool uses_prop_nav{ ECS_obj.get_entity_components(ID).m_uses_prop_nav };

		// == TARGETING ==
		if (target_ID != 0 && !uses_prop_nav) { // if ID is 0, it's not targeting anything

			float spring_constant{ 300000.0f }; // spring constant for damped rotations

			float damping{ 2 * sqrt(spring_constant * moment_of_inertia(mass, shape)) }; // see ideas.txt

			Vector2 target_position{ ECS_obj.get_entity_components(target_ID).m_position };

			// angle to target is the angle of the vector difference of targeting entity and targeted entity

			float target_angle{

				angle_of_vec_diff(position, target_position)

			};

			// finding shortest angular displacement and applying proportional torque

			if (angle - target_angle > PI) { 
				torque += -spring_constant * ((angle - target_angle))- damping * angvel; // see ideas.txt
			}
			else {
				torque += -spring_constant * (angle - target_angle)-damping * angvel;
			};

			//std::cout << "\r" << "angle : " << angle << " | tar angle : " << target_angle << std::flush;

			// === DEBUGGING === //

			//std::cout << "\r" << "lambda_dot : " << lambda_dot << " vs angle buffer " << angle_buffer.at(0) << ", " << angle_buffer.at(1) << ", " << angle_buffer.at(1) << std::flush;

			//std::cout << "\r" << "LOS angle : " << LOS_angle * 180 / PI << " | lambda_dot " << lambda_dot << " | closing vel " << closing_vel << std::flush;


		};

		// == TARGETING (PROPORTIONAL NAV) ==

		if (target_ID != 0 && uses_prop_nav){ // iD == 0 means no target, WIP

			// each frame I need to add the current LOS angle to the target entity to the buffer1 array
			// while also removing the last element
			// I can pop_back buffer1 and then insert LOS angle at index 0

			float LOS_angle = return_LOS_angle(ID);

			std::vector<float> angle_buffer = ECS_obj.get_entity_components(ID).m_buffer1;

			// shifts buffer array: [1,2,3] --> [1,2] 3 --> 0 [1,2] --> [0,1,2,]
			// buffer array used for discrete derivative 

			angle_buffer.pop_back(); // removes last element

			angle_buffer.insert(angle_buffer.begin(), LOS_angle);

			ECS_obj.set_buffer1(ID, angle_buffer);

			// finding lambda_dot now with centered derivative method, taking abs value

			float lambda_dot = num_deriv_array_centered(angle_buffer);

			// finding relative vel

			float closing_vel = - Vector2Length(return_rel_vel(ID, target_ID));

			float N = 3; // going to see if 3 is a good start

			float ang_accel_propnav = return_accel_propnav(N, lambda_dot, closing_vel);

			// now updating torque

			torque = - (moment * ang_accel_propnav) / 50; // need to adjust mass of missile later

			// === DEBUGGING === //

			Vector2 X = ECS_obj.get_entity_components(ID).m_position;

			Vector2 Y = ECS_obj.get_entity_components(target_ID).m_position;

			float look_angle = ECS_obj.get_entity_components(ID).m_angle;

			//std::cout << "\r" << "lambda_dot : " << lambda_dot << " vs angle buffer " << angle_buffer.at(0) << ", " << angle_buffer.at(1) << ", " << angle_buffer.at(1) << std::flush;

			//std::cout << "\r" << "LOS angle : " << LOS_angle * 180 / PI << " | lambda_dot " << lambda_dot << " | closing vel " << closing_vel << std::flush;

			std::cout << "\r" << "angle " << ECS_obj.get_entity_components(ID).m_name << " : " << LOS_angle * 180 / PI << std::flush;
		}

		// == GRAVITY ==

		for (int i = 0; i < ECS_obj.number_of_entities(); i++) { // iterating through ID's

			//std::cout << ECS_map[i].m_name << std::endl;

			if (ECS_obj.get_entity_components(i).m_has_gravity) { // check if entity has gravity attraction enabled

				force += univ_grav(mass, ECS_obj.get_entity_components(i).m_mass, position, ECS_obj.get_entity_components(i).m_position); // add gravity to force vector

			};

		};

		// == KINEMATICS ==

		acceleration = force / mass;

		velocity += acceleration * dt;

		position += velocity * dt + acceleration * 0.5 * dt * dt;

		// angular kinematics (torques, angular velocity, etc)
		// same principle as previous stuff

		angacc = torque / moment;

		angvel += angacc * dt;

		angle += angvel * dt + angacc * 0 * dt * dt;

		// == UPDATING ECS ==

		// only update linear physical components if entity is_movable == true

		if (ECS_obj.get_entity_components(ID).m_is_movable) {

			ECS_obj.set_mass(ID, mass);
			
			ECS_obj.set_position(ID, position);

			ECS_obj.set_velocity(ID, velocity);

			ECS_obj.set_acceleration(ID, acceleration);

			ECS_obj.set_force(ID, force);

			ECS_obj.set_angle(ID, angle);

			ECS_obj.set_angvel(ID, angvel);

			ECS_obj.set_angacc(ID, angacc);

			ECS_obj.set_torque(ID, torque);

			ECS_obj.set_shape(ID, shape);

		}

		// this stuff should be executed IFF the entity is rotatable (may be easier to add a m_is_static component)

		else {

			ECS_obj.set_mass(ID, mass);

			ECS_obj.set_angle(ID, angle);

			ECS_obj.set_angvel(ID, angvel);

			ECS_obj.set_angacc(ID, angacc);

			ECS_obj.set_torque(ID, torque);

			ECS_obj.set_shape(ID, shape);

		};

	};

};