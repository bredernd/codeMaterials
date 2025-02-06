#include <iostream>
using namespace std;

class Vector {
private:
    int x, y;

public:
    // Default constructor
    Vector() : x(0), y(0) {}

    // Constructor with user-defined values
    Vector(int xVal, int yVal) : x(xVal), y(yVal) {}

    // Getter functions
    int getX() const { return x; }
    int getY() const { return y; }

    // Setter functions
    void setX(int xVal) { x = xVal; }
    void setY(int yVal) { y = yVal; }

    // Display function
    void display() const { cout << "(" << x << ", " << y << ")" << endl; }

    // Non-member function declarations
    friend Vector operator+(const Vector &v1, const Vector &v2);
    friend Vector operator-(const Vector &v1, const Vector &v2);
    friend Vector operator-(const Vector &v1);
    friend bool operator==(const Vector &v1, const Vector &v2);
};

// Non-member overloaded operator functions
Vector operator+(const Vector &v1, const Vector &v2) {
    return Vector(v1.x + v2.x, v1.y + v2.y);
}

Vector operator-(const Vector &v1, const Vector &v2) {
    return Vector(v1.x - v2.x, v1.y - v2.y);
}

Vector operator-(const Vector &v1) {
    return Vector(-v1.x, -v1.y);
}

bool operator==(const Vector &v1, const Vector &v2) {
    return (v1.x == v2.x) && (v1.y == v2.y);
}

// Main function to test non-member operators
int main() {
    Vector v1(3, 4), v2(1, 2);

    cout << "Vector v1: ";
    v1.display();
    cout << "Vector v2: ";
    v2.display();

    Vector sum = v1 + v2;
    cout << "v1 + v2: ";
    sum.display();

    Vector diff = v1 - v2;
    cout << "v1 - v2: ";
    diff.display();

    Vector opposite = -v1;
    cout << "-v1: ";
    opposite.display();

    bool isEqual = (v1 == v2);
    cout << "v1 == v2: " << (isEqual ? "true" : "false") << endl;

    return 0;
}
