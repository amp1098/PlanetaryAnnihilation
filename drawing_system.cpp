#include <raylib.h>
#include <raymath.h>
#include "GeneralPolygon.h"
#include "ECS_obj.h"
#include "useful_functions.h"
#include "drawing_system.h"

void draw_lines(std::vector<Vector2> points, Vector2 translate_distance, float rotate_angle, Color color) {
	GeneralPolygon vertices(
		points, color
	);

	vertices.rotate(rotate_angle, Vector2Zero()); // rotates about origin

	vertices.translate(translate_distance.x, translate_distance.y); // translates points

	vertices.draw();
};

float angle_of_vec_diff_dbug(Vector2 vec1, Vector2 vec2) { // remove later, already in physics system, for debugging
	Vector2 vec_res{ vec1 - vec2 };

	return clamp_angle(atan2(vec_res.y, vec_res.x));
};

void draw_entity(int ID) { // render entity with ID <int>(ID) on screen if its spawned
	if (ECS_obj.get_entity_components(ID).m_is_spawned) {
		std::vector<Vector2> points{ ECS_obj.get_entity_components(ID).m_shape };
		Vector2 translate{ ECS_obj.get_entity_components(ID).m_position };
		Vector2 velocity{ ECS_obj.get_entity_components(ID).m_velocity };
		Vector2 force{ ECS_obj.get_entity_components(ID).m_force };
		float rotate_angle{ ECS_obj.get_entity_components(ID).m_angle };
		Color color{ ECS_obj.get_entity_components(ID).m_color };
		int target_ID{ ECS_obj.get_entity_components(ID).m_target_id };

		draw_lines(points, translate, rotate_angle, color);

		// uncomment to debug forces on objects

		//DrawLineV(translate, force * 10 + translate, RED);

		//DrawLineV(translate, velocity + translate, BLUE);

		if (ECS_obj.get_entity_components(ID).m_name == "ship" && target_ID != 0) {
			DrawLineV(translate, Vector2Rotate(Vector2UnitX * 100, rotate_angle) + translate, BLUE); // ship angle
			DrawLineV(translate, Vector2Rotate(Vector2UnitX * 100, angle_of_vec_diff_dbug(ECS_obj.get_entity_components(target_ID).m_position, translate)) + translate, BLUE); // target angle
		};

		if (ECS_obj.get_entity_components(ID).m_name == "ship") {

			float health = ECS_obj.get_entity_components(ID).m_health;

			DrawText(
				TextFormat("Health: %01f ", health),
				ECS_obj.get_entity_components(ID).m_position.x,
				ECS_obj.get_entity_components(ID).m_position.y - 100.0f,
				30,
				RED
			);
		};

		if (ECS_obj.get_entity_components(ID).m_name == "missile") {

			float fuelmass = ECS_obj.get_entity_components(ID).m_fuelmass;

			Vector2 pos = ECS_obj.get_entity_components(ID).m_position;

				/*DrawText(
					TextFormat("Fuelmass: %01f ", fuelmass),
					ECS_obj.get_entity_components(ID).m_position.x,
					ECS_obj.get_entity_components(ID).m_position.y - 100.0f,
					30,
					GREEN
				);*/

			float angle_stuff = rotate_angle - 0 * Vector2Angle(ECS_obj.get_entity_components(target_ID).m_position, pos);

			DrawText(
				TextFormat("Angle: %01f ", round(angle_stuff * 180 / PI)),
				ECS_obj.get_entity_components(ID).m_position.x,
				ECS_obj.get_entity_components(ID).m_position.y - 100.0f,
				30,
				GREEN
			);
		};
	};
};