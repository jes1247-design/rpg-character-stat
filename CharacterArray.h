#ifndef CHARACTERARRAY_H
#define CHARACTERARRAY_H

#include "Character.h"

//This class manages a dynamic array of Character objects
class CharacterArray
{

//This contains the maximum capacity of array and number of elements stored
private:
    Character* arr;
    int size;
    int capacity;

    //This resizes the array when full
    void resize();

public:
    //Constructor
    CharacterArray(); 

    void addCharacter(Character c);
    void removeCharacter(int id);
    Character* searchCharacter(int id);

    void printAll();
    void bubbleSortByName();

    int getSize() const;
    
    void quickSort(int first, int last);
    
    Character* binarySearchById(int id);

    ~CharacterArray(); 
};
#endif