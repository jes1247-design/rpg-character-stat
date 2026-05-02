#ifndef ITEM_H
#define ITEM_H

#include <string>

//This class represents my base class Item
class Item
{
protected:
    std::string name;

public:
     //Default constructor
    Item();
    //Parameterized constructor
    Item(std::string name);

    std::string getName() const;
    void setName(std::string name);

    //Virtual function for printing the details of items
    virtual void print() const;
};

#endif