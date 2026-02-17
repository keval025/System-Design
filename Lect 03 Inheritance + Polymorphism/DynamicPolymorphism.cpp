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

class ManualCar : public Car {
    private: 
        int currentGear;

    public:
        ManualCar(string brand, string model) : Car(brand, model){
            this -> currentGear = 0;
        }

        void shiftGear(int gear){
            currentGear = gear;
            cout << brand << " " << model << ": shifted to gear " << endl;
        }

        void accelerate() {
            if(!isEngineOn){
                cout << brand << " " << model << ": engine is off!" << endl;
                return;
            }
            currentSpeed += 10;
            cout << brand << " " << model << ": accelerating!" << endl;
        }

        void brake() {
            if(!isEngineOn){
                cout << brand << " " << model << ": engine is off!" << endl;
                return;
            }
            currentSpeed -= 10;
            cout << brand << " " << model << ": braking!" << endl;
        }

        ~ManualCar() {
            cout << brand << " " << model << ": manual car destroyed!" << endl;
        }
};

class ElectricCar : public Car {
    private:
        int batteryLevel;

    public:
        ElectricCar(string brand, string model) : Car(brand, model){
            this -> batteryLevel = 100;
        }

        void chargeBattery(){
            batteryLevel = 100;
            cout << brand << " " << model << ": battery is charged!" << endl;
        }

        void accelerate() {
            if(!isEngineOn){
                cout << brand << " " << model << ": engine is off!" << endl;
                return;
            }
            currentSpeed += 10;
            cout << brand << " " << model << ": accelerating!" << endl;
        }

        void brake() {
            if(!isEngineOn){
                cout << brand << " " << model << ": engine is off!" << endl;
                return;
            }
            currentSpeed -= 10;
            cout << brand << " " << model << ": braking!" << endl;
        }

        ~ElectricCar() {
            cout << brand << " " << model << ": electric car destroyed!" << endl;
        }
};

int main() {
    Car* car1 = new ManualCar("Toyota", "Corolla"); // Dynamic Polymorphism for Manual Car
    Car* car2 = new ElectricCar("Tesla", "Model S"); // Dynamic Polymorphism for Electric Car

    car1 -> startEngine();
    car1 -> accelerate();
    car1 -> brake();
    car1 -> stopEngine();

    car2 -> startEngine();
    car2 -> accelerate();
    car2 -> brake();
    car2 -> stopEngine();

    delete car1;
    delete car2;
}