#include <iostream>
#include <cstring>
using namespace std;

class Vehicle
{
protected:
    char model[50];
    float speed;

public:
    void setdetails(const char m[], float s)
    {
        strcpy(model, m);
        speed = s;
    }

    float getSpeed() { return speed; }
    const char *getModel() { return model; }

    virtual void display()
    {
        cout << "Vehicle Model: " << model << ", Speed: " << speed << " km/h" << endl;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle
{
public:
    void calculateTime()
    {
        float distance;
        cout << "Enter distance to be covered by Car: ";
        cin >> distance;
        cout << "Car time for " << distance
             << " km is " << distance / getSpeed() << " hours" << endl;
    }

    void display() override
    {
        cout << "Car Model: " << model << ", Speed: " << speed << " km/h" << endl;
    }
};

class Bike : public Vehicle
{
public:
    void calculateTime()
    {
        float distance;
        cout << "Enter distance to be covered by Bike: ";
        cin >> distance;
        cout << "Bike  time for " << distance
             << " km is " << distance / getSpeed() << " hours" << endl;
    }

    void display() override
    {
        cout << "Bike Model: " << model << ", Speed: " << speed << " km/h" << endl;
    }
};

int main()
{
    int ch;
    char m[50];
    float s;

    do
    {
        cout << "\n1. Enter Car details" << endl;
        cout << "2. Enter Bike details" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        cin.ignore();

        switch (ch)
        {
        case 1:
        {
            Car car;
            cout << "Enter Car model Name: ";
            cin.getline(m, 50);
            cout << "Enter Car Speed (km/h): ";
            cin >> s;
            cin.ignore();
            car.setdetails(m, s);

            car.calculateTime();
            Vehicle *v = &car;
            v->display();
            break;
        }
        case 2:
        {
            Bike bike;
            cout << "Enter Bike model Name: ";
            cin.getline(m, 50);
            cout << "Enter Bike Speed (km/h): ";
            cin >> s;
            cin.ignore();
            bike.setdetails(m, s);

            bike.calculateTime();
            Vehicle *v = &bike;
            v->display();
            break;
        }
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    } while (ch != 0);

    return 0;
}
