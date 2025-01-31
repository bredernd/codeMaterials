#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Point {
private:
    float x;
    float y;

    void checkEntry() {
        if (x < 0 || y < 0) {
            cout << "Error: Negative values are not allowed for x or y. Exiting program." << endl;
            exit(EXIT_FAILURE);
        }
    }

public:

    Point() : x(0), y(0) {}

    Point(float xVal) : x(xVal), y(0) {
        checkEntry();
    }

    Point(float xVal, float yVal) : x(xVal), y(yVal) {
        checkEntry();
    }

    float getX() const {
        return x;
    }

    float getY() const {
        return y;
    }

    static float Manhattan(const Point& p1, const Point& p2) {
        return fabs(p1.x - p2.x) + fabs(p1.y - p2.y);
    }

    static float Euclidean(const Point& p1, const Point& p2) {
        return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    }

    void display() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

int main() {

    Point p1(126, 16);
    Point p2(13, 456);
    Point p3(24, 5);

    cout << "Values of points:" << endl;
    p1.display();
    p2.display();
    p3.display();

    cout << "Manhattan distance between p2 and p3: " << Point::Manhattan(p2, p3) << endl;
    cout << "Euclidean distance between p2 and p3: " << Point::Euclidean(p2, p3) << endl;

    return 0;
}