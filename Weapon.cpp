#include <iostream>
#include "Weapon.h"

//This is my constructor that initializes weapon using Item
Weapon::Weapon(std::string name, int damage) : Item(name)
{
    this->damage = damage;
}

//This displays weapon details
void Weapon::print() const
{
    std::cout << "Weapon: " << name << " Damage: " << damage << std::endl;
}