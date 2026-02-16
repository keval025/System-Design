#include <iostream>
#include <string>

using namespace std;

/*
Dynamic Polymorphism in real life says that 2 Objects coming from same
family will respond to same stimulus differently. Like in real world Manual
car and Electric car will respond to accelerate() differently.

To represent this in programming, we create a parent class that defines all
characters and behaviours that are generic to all child classes and are also same in
all child classes but make those methods abstract(virtual) that are generic to all
child classes but all child class will behave differently. Then those child class
will provide implementation details of these abstract methods the way they want.
*/ 

class Car {
    protected:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;

    public:
        Car(string brand, string model){
            this -> brand = brand;
            this -> model = model;
            this -> isEngineOn = false;
            this -> currentSpeed = 0;
        }

        void startEngine(){
            isEngineOn = true;
            cout << brand << " " << model << ": engine is on!" << endl;
        }

        void stopEngine(){
            isEngineOn = false;
            cout << brand << " " << model << ": engine is off!" << endl;
        }

        virtual void accelerate() = 0; // Abstract method for Dynamic Polymorphism
        virtual void brake() = 0;      // Abstract method for Dynamic Polymorphism

        virtual ~Car() {}              // Virtual destractor
};

