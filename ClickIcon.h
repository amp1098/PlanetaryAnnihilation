#ifndef CLICKICON_H
#define CLICKICON_H

#include <raylib.h>
#include <string>
#include <vector>
#include "ECS.h"

class ClickIcon { // shape that is drawn when you click with the mouse
public:

	int m_ID{};
	std::string m_name{"ClickIcon"};
	float m_mass{0.0f};
	Color m_color{ WHITE };

	// LINEAR COMPONENTS
	Vector2 m_position{};
	Vector2 m_velocity{ 0.0f , 0.0f};
	Vector2 m_acceleration{ 0.0f , 0.0f };
	Vector2 m_force{ 0.0f , 0.0f };

	// ANGULAR COMPONENTS
	float m_angle{ 0.0f };
	float m_angvel{ 0.0f };
	float m_angacc{ 0.0f };
	float m_torque{ 0.0f };

	std::vector<Vector2> m_shape{ {0.0f, 0.0f} }; // vector of Vector2 objects describing entity vertices
	int m_target_id{0}; // missiles and lasers target objects, planetoids do not
	bool m_is_targeted{false}; // anything can be targeted
	bool m_has_gravity{false}; // Planetoids have gravity, ships and stuff do not

	ClickIcon() {// default constructor
		m_ID = -1;
		m_position = { 0.0f, 0.0f };
	};

	ClickIcon(int ID, Vector2 position) { // constructor
		m_ID = ID;
		m_position = position;

		// will draw itself when called

		DrawCircleV(m_position, 30.0f, GREEN);

		set_entity_components( // ECS gets updated upon object creation
			m_ID, m_name, m_mass, m_color,
			m_position, m_velocity, m_acceleration, m_force,
			m_angle, m_angvel, m_angacc, m_torque,
			m_shape,
			m_target_id, m_is_targeted, m_has_gravity
	};
};


#endif