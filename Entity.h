#ifndef ENTITY_H
#define ENTITY_H

#include <string>

//This is the base class for all entities
class Entity
{

protected:
    std::string name;
    int id;

public:
    //Default constructor
    Entity();

    //Parameterized constructor
    Entity(std::string name, int id);

    //Getters
    std::string getName() const;
    int getId() const;

    //Setters
    void setName(std::string name);
    void setId(int id);
};

#endif