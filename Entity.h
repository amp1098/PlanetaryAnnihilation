#ifndef ENTITY_H
#define ENTITY_H

#include "ECS_obj.h"

class Entity { // general entity class 

	int m_ID; // ID number to key entity into ECS map

	entity_row_type m_components; // array of components, e.g. position, name, mass, etc.

public:

	Entity();

	Entity(int ID, entity_row_type components);

	entity_row_type get_components();

	~Entity();

	void remove() const;

};

#endif