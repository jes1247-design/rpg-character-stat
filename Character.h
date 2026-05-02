#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"
#include "LinkedList.h"  

//This class represents a playable character that takes inheritance from Entity
class Character : public Entity
{

private:
    int level;
    int health;

    LinkedList inventory;

public:
    //Default Constructor
    Character();
    //Parametertized Constructor
    Character(std::string name, int id, int level, int health);

    //This prints the characters details
    void printCharacter();
    void addItem(Item* item);
    
    void removeItem(std::string name);
    void showInventory();
};

#endif