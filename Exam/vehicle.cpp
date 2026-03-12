#include <iostream>
#include<cstring>
using namespace std;

class Vehicle {
    private:
        char model[50];
        float speed; // km/h

    public:
        
        void setdetails(const char m[],float s){
            strcpy(model,m);
            speed=s;
        }

        float getSpeed() { return speed; }
};

class Car : public Vehicle {
public:
    void calculateTime() {
        float distance;
        cout << "enter distance to be  covered :";
        cin >> distance;
        cout << "Bike Time for covering "<< distance <<" km is "<< distance / getSpeed() << "hours" << endl; 
    }
};

class Bike : public Vehicle {
public:

    void calculateTime() {
        float distance;
        cout << "enter distance to be  covered :";
        cin >> distance;
        cout << "Bike Time for covering "<< distance <<" km is "<< distance / getSpeed() << " hours" << endl;    
    }
};

int main() {
    int ch;
    char m[50];
    float s;
    do{
        cout << "1. Enter car details"<< endl;
        cout << "2. Enter Bike details"<< endl;
        cout << "0. Exit"<< endl;
        cin >> ch;
        cin.ignore();

        switch (ch)
        {
        case 1:
            Car car;
            cout << "Enter Car model Name :";
            cin.getline(m, 50);
            cout <<"Enter Car Speed (km/h) :"; 
            cin >> s;
            cin.ignore();
            car.setdetails(m,s);

            car.calculateTime();
            break;
        case 2:
            Bike bike;
            cout << "Enter Bike Model Name :";
            cin.getline(m, 50);
            cout <<"Enter Bike Speed (km/h) :"; 
            cin >> s;
            cin.ignore();
            bike.setdetails(m,s);

            bike.calculateTime();
            break;
        case 0: 
            break;
        default:
            cout<<"Invalid Choice";
        }
    }while(ch != 0);
    return 0;
}
