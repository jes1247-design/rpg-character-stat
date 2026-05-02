#include <iostream>
#include "Item.h"

//Default constructor
Item::Item()
{
    name = "";
}

//Parameterized constructor
Item::Item(std::string name)
{
    this->name = name;
}

//This returns the name
std::string Item::getName() const
{
    return name;
}

void Item::setName(std::string name)
{
    this->name = name;
}

//This prints out basic item info/stats
void Item::print() const
{
    std::cout << "Item: " << name << std::endl;
}