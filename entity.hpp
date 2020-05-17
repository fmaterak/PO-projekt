#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>

class EntityManager;

class Entity
{
	public:

	std::string id;

	Entity(std::string id)
	{
		this->id = id;
	}

	// Destructor must be made virtual as all derived classes are
	// treated as Entity in the EntityManager
	virtual ~Entity() {}
};

#endif /* ENTITY_HPP */
