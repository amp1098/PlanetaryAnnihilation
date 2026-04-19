#include "Entity.h"

Entity::Entity() {
	m_ID = 0;
	m_components = {};
};

Entity::Entity(int ID, entity_row_type components) {

	m_ID = ID;
	m_components = components;

};

entity_row_type Entity::get_components() {
	return ECS_obj.get_entity_components(m_ID);
};

Entity::~Entity() { // destructor, object removal also  removes it from ECS
	ECS_obj.destroy_entity(m_ID);
};

void Entity::remove() const {
	ECS_obj.destroy_entity(m_ID);

	//std::cout << "\n" << m_ID << std::flush;
};