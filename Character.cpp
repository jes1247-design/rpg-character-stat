#include <iostream>
#include "Character.h"
#include "LinkedList.h"
#include "Item.h"

//Default constructor
Character::Character() : Entity()
{
    level = 1;
    health = 100;
}

// Parameterized constructor
Character::Character(std::string name, int id, int level, int health) : Entity(name, id)
{
    this->level = level;
    this->health = health;
}

//Print character info 
void Character::printCharacter() 
{
    std::cout << "Character Info:\n";
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Health: " << health << std::endl;

    std::cout << "Inventory";
    inventory.printList();
}

//This adds item to inventory
void Character::addItem(Item* item)
{
    inventory.addItem(item);
}

//This removes item form inventory
void Character::removeItem(std::string name)
{
    inventory.removeItem(name);
}

//This shows inventory 
void Character::showInventory()
{
    std::cout << "Inventory for " << getName() << ":" << std::endl;
    inventory.printList();
}