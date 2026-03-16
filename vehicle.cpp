#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    int vehicleID;
    string manufacturer;
    string model;
    int year;
    static int totalVehicles;

public:
    Vehicle(int id = 0, string manu = "Unknown", string mod = "Unknown", int yr = 0)
    {
        vehicleID = id;
        manufacturer = manu;
        model = mod;
        year = yr;
        totalVehicles++;
    }

    ~Vehicle()
    {
        cout << "Vehicle with ID " << vehicleID << " destroyed.\n";
    }

    int getVehicleID() const { return vehicleID; }
    void setVehicleID(int id) { vehicleID = id; }

    string getManufacturer() const { return manufacturer; }
    void setManufacturer(string manu) { manufacturer = manu; }

    string getModel() const { return model; }
    void setModel(string mod) { model = mod; }

    int getYear() const { return year; }
    void setYear(int yr) { year = yr; }

    static int getTotalVehicles() { return totalVehicles; }

    virtual void display() const
    {
        cout << "ID: " << vehicleID << ", Manufacturer: " << manufacturer
             << ", Model: " << model << ", Year: " << year << endl;
    }
};
int Vehicle::totalVehicles = 0;

class Car : public Vehicle
{
private:
    string fuelType;

public:
    Car(int id = 0, string manu = "Unknown", string mod = "Unknown", int yr = 0, string fuel = "Petrol")
        : Vehicle(id, manu, mod, yr), fuelType(fuel) {}
    void display() const override
    {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class ElectricCar : public Car
{
private:
    int batteryCapacity;

public:
    ElectricCar(int id = 0, string manu = "Unknown", string mod = "Unknown", int yr = 0, string fuel = "Electric", int battery = 0)
        : Car(id, manu, mod, yr, fuel), batteryCapacity(battery) {}
    void display() const override
    {
        Car::display();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

class SportsCar : public ElectricCar
{
private:
    int topSpeed;

public:
    SportsCar(int id = 0, string manu = "Unknown", string mod = "Unknown", int yr = 0, string fuel = "Petrol", int battery = 0, int speed = 0)
        : ElectricCar(id, manu, mod, yr, fuel, battery), topSpeed(speed) {}
    void display() const override
    {
        ElectricCar::display();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};

class Aircraft
{
protected:
    int flightRange;

public:
    Aircraft(int range = 0) : flightRange(range) {}
    virtual void display() const
    {
        cout << "Flight Range: " << flightRange << " km" << endl;
    }
};

class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar(int id = 0, string manu = "Unknown", string mod = "Unknown", int yr = 0, string fuel = "Hybrid", int range = 0)
        : Car(id, manu, mod, yr, fuel), Aircraft(range) {}
    void display() const override
    {
        Car::display();
        Aircraft::display();
    }
};

class Sedan : public Car
{
public:
    Sedan(int id = 0, string manu = "Unknown", string mod = "Unknown", int yr = 0, string fuel = "Petrol")
        : Car(id, manu, mod, yr, fuel) {}
    void display() const override
    {
        Car::display();
        cout << "Type: Sedan" << endl;
    }
};

class SUV : public Car
{
public:
    SUV(int id = 0, string manu = "Unknown", string mod = "Unknown", int yr = 0, string fuel = "Diesel")
        : Car(id, manu, mod, yr, fuel) {}
    void display() const override
    {
        Car::display();
        cout << "Type: SUV" << endl;
    }
};

class VehicleRegistry
{
private:
    Vehicle vehicles[50];
    int count;

public:
    VehicleRegistry() : count(0) {}

    void addVehicle(const Vehicle &v)
    {
        if (count < 50)
        {
            vehicles[count++] = v;
        }
    }

    void displayAll() const
    {
        for (int i = 0; i < count; i++)
        {
            vehicles[i].display();
            cout << "-------------------\n";
        }
    }

    void searchById(int id) const
    {
        for (int i = 0; i < count; i++)
        {
            if (vehicles[i].getVehicleID() == id)
            {
                vehicles[i].display();
                return;
            }
        }
        cout << "Vehicle not found!\n";
    }
};

int main()
{
    VehicleRegistry registry;
    int choice;

    do
    {
        cout << "\n--- Vehicle Registry Menu ---\n";
        cout << "1. Add Car\n2. Add Electric Car\n3. Add Sports Car\n4. Add Flying Car\n5. Add Sedan\n6. Add SUV\n7. View All Vehicles\n8. Search by ID\n9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id, yr;
            string manu, mod, fuel;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Manufacturer: ";
            cin >> manu;
            cout << "Enter Model: ";
            cin >> mod;
            cout << "Enter Year: ";
            cin >> yr;
            cout << "Enter Fuel Type: ";
            cin >> fuel;
            Car c(id, manu, mod, yr, fuel);
            registry.addVehicle(c);
        }
        else if (choice == 2)
        {
            int id, yr, battery;
            string manu, mod, fuel;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Manufacturer: ";
            cin >> manu;
            cout << "Enter Model: ";
            cin >> mod;
            cout << "Enter Year: ";
            cin >> yr;
            cout << "Enter Fuel Type: ";
            cin >> fuel;
            cout << "Enter Battery Capacity: ";
            cin >> battery;
            ElectricCar e(id, manu, mod, yr, fuel, battery);
            registry.addVehicle(e);
        }
        else if (choice == 3)
        {
            int id, yr, battery, speed;
            string manu, mod, fuel;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Manufacturer: ";
            cin >> manu;
            cout << "Enter Model: ";
            cin >> mod;
            cout << "Enter Year: ";
            cin >> yr;
            cout << "Enter Fuel Type: ";
            cin >> fuel;
            cout << "Enter Battery Capacity: ";
            cin >> battery;
            cout << "Enter Top Speed: ";
            cin >> speed;
            SportsCar s(id, manu, mod, yr, fuel, battery, speed);
            registry.addVehicle(s);
        }
        else if (choice == 4)
        {
            int id, yr, range;
            string manu, mod, fuel;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Manufacturer: ";
            cin >> manu;
            cout << "Enter Model: ";
            cin >> mod;
            cout << "Enter Year: ";
            cin >> yr;
            cout << "Enter Fuel Type: ";
            cin >> fuel;
            cout << "Enter Flight Range: ";
            cin >> range;
            FlyingCar f(id, manu, mod, yr, fuel, range);
            registry.addVehicle(f);
        }
        else if (choice == 5)
        {
            int id, yr;
            string manu, mod, fuel;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Manufacturer: ";
            cin >> manu;
            cout << "Enter Model: ";
            cin >> mod;
            cout << "Enter Year: ";
            cin >> yr;
            cout << "Enter Fuel Type: ";
            cin >> fuel;
            Sedan sd(id, manu, mod, yr, fuel);
            registry.addVehicle(sd);
        }
        else if (choice == 6)
        {
            int id, yr;
            string manu, mod, fuel;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Manufacturer: ";
            cin >> manu;
            cout << "Enter Model: ";
            cin >> mod;
            cout << "Enter Year: ";
            cin >> yr;
            cout << "Enter Fuel Type: ";
            cin >> fuel;
            SUV suv(id, manu, mod, yr, fuel);
            registry.addVehicle(suv);
        }
        else if (choice == 7)
        {
            registry.displayAll();
        }
        else if (choice == 8)
        {
            int id;
            cout << "Enter Vehicle ID: ";
            cin >> id;
            registry.searchById(id);
        }
    } while (choice != 9);

    cout << "Exiting Vehicle Registry System...\n";
    return 0;
}
