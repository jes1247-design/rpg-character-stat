#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

//This class represents an enemy that takes inheritance from Entity
class Enemy : public Entity
{

private:
    int damage;

public:
    //Default constructor
    Enemy();
    
    //Parameterized constructor
    Enemy(std::string name, int id, int damage);

    void printEnemy();
};

#endif