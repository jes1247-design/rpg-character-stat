#include <iostream>
#include "Enemy.h"

//Tghis is my default constructor
Enemy::Enemy() : Entity()
{
    damage = 0;
}

//This is my parameterized constructor
Enemy::Enemy(std::string name, int id, int damage) : Entity(name, id)
{
    this->damage = damage;
}

//This contains my print function
void Enemy::printEnemy()
{
    std::cout << "Enemy Info:" << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Damage: " << damage << std::endl;
}