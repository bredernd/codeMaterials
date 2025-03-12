#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Animal {
protected:
    int id;
    string name;
    string shelter;

public:
    // Default Constructor
    Animal() : id(0), name("Unknown"), shelter("Unknown") {}

    // Parameterized Constructor
    Animal(int _id, string _name, string _shelter) : id(_id), name(_name), shelter(_shelter) {}

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    string getShelter() const { return shelter; }

    // Setters
    void setId(int _id) { id = _id; }
    void setName(string _name) { name = _name; }
    void setShelter(string _shelter) { shelter = _shelter; }

    // Pure virtual function (Abstract class)
    virtual void makeSound() = 0;

    // Virtual Destructor
    virtual ~Animal() {}
};

#endif //ANIMAL_H
