#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Item.h"

//This is the node structure
class Node
{

public:
    Item* data;
    Node* next;

    Node(Item* item);
};

//This is the linked list class for the player inventory
class LinkedList
{
private:
    Node* head;

public:
    //Constructor
    LinkedList();

    bool isEmpty() const;
    void addItem(Item* item);

    void removeItem(std::string name);
    void printList() const;

    //Destructor
    ~LinkedList();
};

#endif