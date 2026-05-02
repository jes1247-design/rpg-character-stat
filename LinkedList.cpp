#include <iostream>
#include "LinkedList.h"

using namespace std;

//Node constructor
Node::Node(Item* item)
{
    data = item;
    next = nullptr;
}

//LinkedList constructor
LinkedList::LinkedList()
{
    head = nullptr;
}

bool LinkedList::isEmpty() const
{
    return head == nullptr;
}

//This adds an item to the front
void LinkedList::addItem(Item* item)
{
    Node* tempPtr = new Node(item);
    tempPtr->next = head;
    head = tempPtr;
}

//Remove item based on name
void LinkedList::removeItem(string name)
{
    if (isEmpty())
    {
        cout << "The inventory is empty" << endl;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr)
    {
        if (current->data->getName() == name)
        {
            if (prev == nullptr)
                head = current->next;
            
            else
                prev->next = current->next;

            delete current;
            
            cout << "Item removed." << endl;
            return;
        }

        prev = current;
        current = current->next;
    }

    cout << "Item not found." << endl;
}

//Print inventory
void LinkedList::printList() const
{
    Node* temp = head;

    if (temp == nullptr)
    {
        cout << "Inventory is empty." << endl;
        return;
    }

    while (temp != nullptr)
    {
        temp->data->print();
        
        temp = temp->next;
    }
}

//Destructor
LinkedList::~LinkedList()
{
    Node* temp;

    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        
        delete temp;
    }
}