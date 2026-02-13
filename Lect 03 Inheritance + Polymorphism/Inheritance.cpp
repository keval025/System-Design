#include <iostream>
#include <string>

using namespace std;

/*
We know that real world Objects show inheritance relationship where we
have parent object and child object. child object have all the characters
or behaviours that parent have plus some additional characters/behaviours.
Like all cars in real world have a brand, model etc and can start, stop, 
accelerate etc. But some specific cars like manual car have gear System
while other specific cars like Electric cars have battery system.

We represent this scenario of real world in programming by creating a parent class and
defining all the characters(variables) or behaviours(methods) that all cars 
have in parent class. Then we create different child classes that inherits 
from this parent class and define only those characters and behaviours
that are specific to them. Although objects of these child classes can 
access or call parent class characters(variables) and behaviours(methods).
Hence providing code reusability.
*/

class Car {
    protected:
        string brand;
        string model:
        bool isEngineOn;
        int currentSpeed;

    public:
        Car(string s, string m){
            this -> brand = s;
            this -> model = m;
            isEngineOn = false;
            currentSpeed = 0;
        }

        //Common methods for All cars.
        void startEngine() {
            isEngineOn= true;
            cout << brand << " " << model << ": Engine is start now" << endl;
        }

        void stopEngine(){
            isEngineOn = false;
            cout << brand << " " << model << ": Engine is stop now" << endl;
        }

        void accelerate(){
            if(!isEngineOn){
                cout << brand << " " << model << ": first start engine" << endl;
                return;
            }
            currentSpeed += 10;
            cout << brand << " " << model << ": current speed of the car is -> " << currentSpeed << endl;        
        }

        void brake() {
            currentSpeed -= 10;
            if(currentSpeed < 0) currentSpeed = 0;
            cout << brand << " " << model << ": current speed of the car is -> " << currentSpeed << endl;
        }

        virtual ~Car() {}
};

class ManualCar : public Car { // Inheritance from Car class
    private:
        int curretnGear; //Specific to manual car only

    public:
        ManualCar(string s, string m) : Car(s, m) {
            currentGear = 0;
        }

        //Specific Method for manual car
        void shiftGear(int gear){
            curretnGear = gear;
            cout << brand << " " << model << ": current gear is -> " << currentGear << endl;
        }
};

class ElectricCar : public Car {
    private:
        int batteryLevel;
    
    public:
        ElectricCar(string s, string m) : Car(s, m){
            batteryLevel = 100;
        }

        void changeBattery() {
            batterylevel  100;
            cout << brand << " " << model << ": battery level is -> " << batterylevel  << endl;
        }
};

int main() {

    ManualCar* myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();
    myManualCar->shiftGear(1); //specific to manual car
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;

    cout << "----------------------" << endl;

    ElectricCar* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->chargeBattery(); //specific to electric car
    myElectricCar->startEngine(); 
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();
    delete myElectricCar; 

    return 0;
}