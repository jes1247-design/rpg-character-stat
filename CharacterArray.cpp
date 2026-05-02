#include <iostream>
#include "CharacterArray.h"

using namespace std;

//This is a constructor that initializes array
CharacterArray::CharacterArray()
{
    capacity = 2;
    size = 0;
    arr = new Character[capacity];
}

//This is my destructor 
CharacterArray::~CharacterArray()
{
    delete[] arr;
}

//This resizes array when full
void CharacterArray::resize()
{
    capacity *= 2;

    Character* newArr = new Character[capacity];

    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
}

//This adds a new character
void CharacterArray::addCharacter(Character c)
{
    if (size == capacity)
    {
        resize();
    }

    arr[size] = c;
    size++;
}

//This removes character by ID
void CharacterArray::removeCharacter(int id)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].getId() == id)
        {
            for (int j = i; j < size - 1; j++)
            {
                arr[j] = arr[j + 1];
            }

            size--;
            cout << "Character removed." << endl;
            return;
        }
    }

    cout << "Character was not found." << endl;
}

//This contains my linear search
Character* CharacterArray::searchCharacter(int id)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].getId() == id)
            return &arr[i];
    }

    return nullptr;
}

//This prints all characters
void CharacterArray::printAll()
{
    for (int i = 0; i < size; i++)
    {
        arr[i].printCharacter();
        cout << "-----------------" << endl;
    }
}

//This does bubble sort
void CharacterArray::bubbleSortByName()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j].getName() > arr[j + 1].getName())
            {
                Character temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Characters sorted by name." << endl;
}

//This returns the current size of array
int CharacterArray::getSize() const
{
    return size;
}

void swap(Character& a, Character& b)
{
    Character temp;
    temp = a;
    a = b;
    b = temp;
}

//This is my split function
void split(Character values[], int first, int last, int& splitPoint)
{
    Character pivot = values[first];
    int saveFirst = first;

    bool correct;

    first++;

    do
    {
        correct = true;

        while (correct)
        {
            if (values[first].getId() > pivot.getId())
                correct = false;
            else
            {
                first++;
                correct = (first <= last);
            }
        }

        correct = (first <= last);

        while (correct)
        {
            if (values[last].getId() <= pivot.getId())
                correct = false;
            else
            {
                last--;
                correct = (first <= last);
            }
        }

        if (first < last)
        {
            swap(values[first], values[last]);
            first++;
            last--;
        }

    } while (first <= last);

    //This is to place pivot correctly
    splitPoint = last;
    swap(values[saveFirst], values[splitPoint]);
}

//This is my quick sort
void CharacterArray::quickSort(int first, int last)
{
    if (first < last)
    {
        int splitPoint;

        split(arr, first, last, splitPoint);

        quickSort(first, splitPoint - 1);

        quickSort(splitPoint + 1, last);
    }
}

//This is my binary search 
Character* CharacterArray::binarySearchById(int id)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid].getId() == id)
            return &arr[mid];

        else if (arr[mid].getId() < id)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return nullptr;
}