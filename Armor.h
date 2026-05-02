#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

//This class represents the "Armor" item that is taken from the main Item
class Armor : public Item
{

private:
    int defense;

public:
    //Constructor that takes into account name and defense
    Armor(std::string name, int defense);

    void print() const override;
};

#endif