#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal {
public:
    // Default Constructor
    Cat() {}

    // Parameterized Constructor
    explicit Cat(int _id, string _name, string _shelter) : Animal(_id, _name, _shelter) {}

    // Override makeSound()
    void makeSound() override {
        cout << "Meow Meow!" << endl;
    }
};

#endif // CAT_H
