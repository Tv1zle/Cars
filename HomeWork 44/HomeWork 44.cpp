#include <iostream>
using namespace std;


class Wheels
{
protected:
    int countw;
public:
    Wheels(int c)
    {
        countw = c;
    }
};

class Engine
{
protected:
    int power;
public:
    Engine(int p)
    {
        power = p;
    }
};


class Doors
{
protected:
    int countd;
public:
    Doors(int c)
    {
        countd = c;
    }
};


class Cars : public Wheels, public Engine, public Doors
{
public:
    Cars(int wc, int ep, int dc) : Wheels(wc), Engine(ep), Doors(dc) {}
    void drive()
    {
        cout << "Driving car with " << countw << " wheels, " << power << " hp engine, and " << countd << " doors." << endl;
    }
};


class Transport
{
public:
    virtual void printType()
    {
        cout << "This is a generic transport vehicle." << endl;
    }
    virtual float fuelConsumption() 
    {
        return 0.0;
    }
};

class Airplane : public Transport
{
public:
    void printType() 
    {
        cout << "This is an airplane." << endl;
    }
    float fuelConsumption()
    {
        return 10.0;
    }
};

class Ship : public Transport 
{
public:
    void printType() 
    {
        cout << "This is a ship." << endl;
    }
    float fuelConsumption() 
    {
        return 20.0;
    }
};

class Truck : public Transport 
{
public:
    void printType()
    {
        cout << "This is a truck." << endl;
    }
    float fuelConsumption()
    {
        return 15.0;
    }
};


class Bicycle : public Transport
{
public:
    void printType()
    {
        cout << "This is a bicycle." << endl;
    }
    float fuelConsumption() 
    {
        return 0.0;
    }
};


class Car : public Transport
{
public:
    void printType()
    {
        cout << "This is a car." << endl;
    }
    float fuelConsumption() 
    {
        return 12.0;
    }
};


int main()
{
    Cars myCar(4, 200, 4);
    myCar.drive();


    int choice;
    Transport* vehicle;


    cout << "Select a vehicle type:" << endl;
    cout << "1. Airplane" << endl;
    cout << "2. Ship" << endl;
    cout << "3. Truck" << endl;
    cout << "4. Bicycle" << endl;
    cout << "5. Car" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        vehicle = new Airplane();
        break;
    case 2:
        vehicle = new Ship();
        break;
    case 3:
        vehicle = new Truck();
        break;
    case 4:
        vehicle = new Bicycle();
        break;
    case 5:
        vehicle = new Car();
        break;
    default:
        cout << "Invalid choice." << endl;
        return 0;
    }


    vehicle->printType();
    cout << "Fuel consumption: " << vehicle->fuelConsumption() << " liters per 100 km.";
}