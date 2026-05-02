# RPG Character Management System (C++)

## Overview

This project is a command-line RPG character management system developed in C++. It allows users to create and manage characters, assign items such as weapons and armor, and perform operations like sorting, searching, and inventory management.

The system is designed using object-oriented programming principles and implements custom data structures and algorithms to manage game data efficiently.

## Features

* Create and manage RPG characters (name, ID, level, health)
* Add and remove items (weapons and armor) to character inventories
* View and manage inventory using a custom linked list
* Sort characters using bubble sort and quicksort
* Search characters using linear and binary search
* Undo last action using a stack-based system
* Save and load character data using file I/O
* Custom exception handling for robust input and file operations

## Technologies Used

* C++
* Object-Oriented Programming (OOP)
* Custom Data Structures (Linked List, Dynamic Array)
* Algorithms (Sorting and Searching)
* File I/O
* Exception Handling

## System Design

The project is structured using a modular class hierarchy:

* **Entity** (base class)

  * Character
  * Enemy
* **Item** (base class)

  * Weapon
  * Armor
* **Inventory System**

  * LinkedList (custom implementation)
* **Character Management**

  * Dynamic array with resizing

This design promotes code reusability, scalability, and separation of concerns.

## How to Compile and Run

### Compile

```bash
g++ main.cpp Character.cpp CharacterArray.cpp Entity.cpp Enemy.cpp Item.cpp Weapon.cpp Armor.cpp LinkedList.cpp -o program
```

### Run

```bash
./program
```

## Example Usage

===== RPG Manager =====
1. Add Character
2. View All Characters
3. Add Item to Character
4. View Character Inventory

Users can interact with the menu to manage characters and their inventories.

## What I Learned

* Designing and implementing modular C++ systems
* Applying object-oriented principles (inheritance, polymorphism)
* Building custom data structures from scratch
* Implementing sorting and searching algorithms
* Managing memory and pointers in C++
* Handling user input and file operations safely

## Future Improvements

* Add combat system between characters and enemies
* Implement persistent storage for full character data
* Add graphical interface (GUI)
* Improve error handling and validation

## Author

Jordan Schmitt
