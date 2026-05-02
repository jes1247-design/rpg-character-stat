#include <iostream>
#include "Armor.h"

//This is my constructor that initializes the "Armor"  
Armor::Armor(std::string name, int defense) : Item(name)
{
    this->defense = defense;
}

void Armor::print() const
{
    std::cout << "Armor: " << name << " Defense: " << defense << std::endl;
}