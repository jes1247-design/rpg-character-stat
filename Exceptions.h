#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

//This is thrown when an item cannot be found
class ItemNotFoundException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Item not found.";
    }
};

//This is thrown when the input is invalid
class InvalidInputException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Invalid input.";
    }
};

//This is thrown when there is a file error
class FileException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "File error.";
    }
};

#endif