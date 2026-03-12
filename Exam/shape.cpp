#include <iostream>
using namespace std;

class Shape {
public:
    
    virtual double calculateArea() = 0;
    virtual void draw() = 0;

};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) { radius = r; }

    double calculateArea() override {
        return 3.14 * radius * radius;
    }

    void draw() override {
        cout << "Drawing Circle with radius " << radius << endl;
    }
};
class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double calculateArea() override {
        return length * width;
    }

    void draw() override {
        cout << "Drawing Rectangle of " << length << " x " << width << endl;
    }
};

int main() {
    int r,l,w;
    Shape* shapes[2];

    cout << "Enter Radius of a circle to calculate its area and draw it :";
    cin >> r;
    shapes[0] = new Circle(r);

    cout << "enter lenght of rectangle :";
    cin>> l;
    cout << "enter width of rectangle :";
    cin>> w;
    shapes[1] = new Rectangle(l, w);

    cout << "\n--- Demonstrating Polymorphism with Shapes ---\n";
    for (int i = 0; i < 2; i++) {
        shapes[i]->draw();

        cout << "Area: " << shapes[i]->calculateArea() << endl;
    }


    return 0;
}
