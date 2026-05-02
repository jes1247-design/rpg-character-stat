#include "Entity.h"

//This is my default constructor
Entity::Entity()
{
    name = "";
    id = 0;
}

//This is my parameterized constructor
Entity::Entity(std::string name, int id)
{
    this->name = name;
    this->id = id;
}

//This contains my getters
std::string Entity::getName() const
{
    return name;
}

int Entity::getId() const
{
    return id;
}

//This contains my setters
void Entity::setName(std::string name)
{
    this->name = name;
}

void Entity::setId(int id)
{
    this->id = id;
}