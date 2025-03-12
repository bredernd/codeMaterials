#include "Horse.h"
#include "Cat.h"

int main() {
    // Creating objects with parameterized constructors
    Horse horse1(1, "Thunder", "Yellow Stone Ranch");
    Cat cat1(2, "Whiskers", "Meowth Shelter");

    // Calling makeSound() for each
    cout << horse1.getName() << " says: ";
    horse1.makeSound();

    cout << cat1.getName() << " says: ";
    cat1.makeSound();

    return 0;
}
