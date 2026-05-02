#include <iostream>
#include <stack>
#include <fstream>
#include "CharacterArray.h"
#include "Weapon.h"
#include "Armor.h"
#include "Exceptions.h"

// Save characters
void saveCharacters(CharacterArray& characters)
{
    std::ofstream file("characters.txt");

    if (!file)
        throw FileException();

    file << "Characters saved." << std::endl;
    file.close();
}

//This is my load characters function
void loadCharacters()
{
    std::ifstream file("characters.txt");

    if (!file)
        throw FileException();

    std::string line;
    while (getline(file, line))
    {
        std::cout << line << std::endl;
    }

    std::cout << "Character(s) loaded." << std::endl;

    file.close();
}

int main()
{
    CharacterArray characters;
    std::stack<std::string> actions;

    int choice;

    do
    {
        std::cout << std::endl;
        std::cout << "===== RPG Manager =====" << std::endl;
        std::cout << "1. Add Character" << std::endl;
        std::cout << "2. View All Characters" << std::endl;
        std::cout << "3. Add Item to Character" << std::endl;
        std::cout << "4. View Character Inventory" << std::endl;
        std::cout << "5. Remove Character" << std::endl;
        std::cout << "6. Sort Characters" << std::endl;
        std::cout << "7. Undo Last Action" << std::endl;
        std::cout << "8. Save Characters" << std::endl;
        std::cout << "9. Load Characters" << std::endl;
        std::cout << "10. Remove Item from Character" << std::endl;
        std::cout << "Enter choice: ";

        std::cin >> choice;

        //This section contains my add character functionality
        if (choice == 1)
        {
            std::string name;
            int id, level, health;

            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter ID: ";
            std::cin >> id;
            std::cout << "Enter level: ";
            std::cin >> level;
            std::cout << "Enter health: ";
            std::cin >> health;

            characters.addCharacter(Character(name, id, level, health));
            actions.push("Added Character: " + name);
        }

        //View all
        else if (choice == 2)
        {
            characters.printAll();
        }

        //This section contains my add item functionality
        else if (choice == 3)
        {
            int id;
            std::cout << "Enter character ID: ";
            std::cin >> id;

            Character* c = characters.searchCharacter(id);

            if (c == nullptr)
            {
                std::cout << "Character not found." << std::endl;
                continue;
            }

            int type;
            std::cout << "1. Weapon  2. Armor: ";
            std::cin >> type;

            std::string name;
            std::cout << "Enter the item name: ";
            std::cin >> name;

            if (type == 1)
            {
                int damage;
                std::cout << "Enter the amount of damage: ";
                std::cin >> damage;

                c->addItem(new Weapon(name, damage));
                actions.push("Added Weapon: " + name);
            }
            else if (type == 2)
            {
                int defense;
                std::cout << "Enter defense: ";
                std::cin >> defense;

                c->addItem(new Armor(name, defense));
                actions.push("Added Armor: " + name);
            }
        }

        //This makes it so that you can view the inventory
        else if (choice == 4)
        {
            try
            {
                int id;
                std::cout << "Enter character ID: ";
                std::cin >> id;

                Character* c = characters.searchCharacter(id);

                if (c == nullptr)
                    throw InvalidInputException();

                c->showInventory();
            }
            catch (InvalidInputException& e)
            {
                std::cout << e.what() << std::endl;
            }
        }

        //This removes the character
        else if (choice == 5)
        {
            int id;
            std::cout << "Enter character ID to remove: ";
            std::cin >> id;

            characters.removeCharacter(id);
            actions.push("Removed Character ID: " + std::to_string(id));
        }

        //Sort function
        else if (choice == 6)
        {
            characters.bubbleSortByName();
        }

        //This contains my undo stack function
        else if (choice == 7)
        {
            if (actions.empty())
            {
                std::cout << "There is nothing to undo." << std::endl;
            }
            else
            {
                std::cout << "Undo: " << actions.top() << std::endl;
                actions.pop();
            }
        }

        //Save
        else if (choice == 8)
        {
            try
            {
                saveCharacters(characters);
                std::cout << "Saved successfully!" << std::endl;
            }
            catch (FileException& e)
            {
                std::cout << e.what() << std::endl;
            }
        }

        //This is my load function for my character
        else if (choice == 9)
        {
            try
            {
                loadCharacters();
            }
            catch (FileException& e)
            {
                std::cout << e.what() << std::endl;
            }
        }

        //This removes the item
        else if (choice == 10)
        {
            int id;
            std::cout << "Enter the character ID: ";
            std::cin >> id;

            Character* c = characters.searchCharacter(id);

            if (c == nullptr)
            {
                std::cout << "Character not found" << std::endl;
                continue;
            }

            std::string itemName;
            std::cout << "Enter the item name you want to remove: ";
            std::cin >> itemName;

            c->removeItem(itemName);
        }

    } 
    while (choice != 0);

    std::cout << "Exiting the program..." << std::endl;
    return 0;
}