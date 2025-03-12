#ifndef HORSE_H
#define HORSE_H

#include "Animal.h"

class Horse : public Animal {
public:
    // Default Constructor
    Horse() {}

    // Parameterized Constructor
    explicit Horse(int _id, string _name, string _shelter) : Animal(_id, _name, _shelter) {}

    // Override makeSound()
    void makeSound() override {
        cout << "Neigh Neigh!" << endl;
    }
};

#endif // HORSE_H

