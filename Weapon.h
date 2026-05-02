#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

//This class represents a weapon that takes inheritence from Item
class Weapon : public Item
{

private:
    int damage;

public:
     //Constructor
    Weapon(std::string name, int damage);

    void print() const override;
};

#endif