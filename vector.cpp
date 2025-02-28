#include <iostream>
#include <math.h>
using namespace std;

class Vector2d
{
private:
    double x;
    double y;

public:
    Vector2d(double currX, double currY)
    {
        x = currX;
        y = currY;
    }

    void addVectors(Vector2d currVector)
    {
        x += currVector.getX();
        y += currVector.getY();
    }

    double getDistance()
    {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    void changeSize(double k)
    {
        x *= k;
        y *= k;
    }

    double getX()
    {
        return x;
    }

    double getY()
    {
        return y;
    }

    void normalize()
    {
        double magnitude = getDistance();
        x /= magnitude;
        y /= magnitude;
    }

    void printVector()
    {
        cout << "{ " << getX() << ", " << getY() << " }\n";
    }
};

int main()
{
    Vector2d currVector(3, 4), secVector(3, 4);
    cout << "Vector: ";
    currVector.printVector();
    currVector.addVectors(secVector);
    cout << "Sum of Vectors: ";
    currVector.printVector();
    cout << "Distance: " << currVector.getDistance() << "\n";
    cout << "Change Size: ";
    currVector.changeSize(0.5);
    currVector.printVector();
    cout << "Normalized: ";
    currVector.normalize();
    currVector.printVector();
    return 0;
}