#include "Entity.h"

Entity::Entity(int ID, entity_row_type components) {

	m_ID = ID;
	m_components = components;

};

entity_row_type Entity::get_components() {
	return ECS_obj.get_entity_components(m_ID);
};

void Entity::remove() const {
	ECS_obj.destroy_entity(m_ID);
};