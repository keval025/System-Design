#include <iostream>
#include <string>

using namespace std;

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
            cout << brand << " " << model << ": engine is on " << endl;
        }
        
        void stopEngine(){
            isEngineOn = false;
            currentSpeed =0;
            cout << brand << " " << model << ": engine is off " << endl;  
        }

        virtual void accelerate() = 0; //Abstract method for Dynamic Polymorphism
        virtual void accelerate(int speed) = 0; //Abstract method for Static Polymorphism

        virtual void brake() = 0; //Abstract method for Dynamic polymorphism

        virtual ~Car() {}; //Virtual Destructor

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
            cout << brand << " " << model << ": Shifted to gear " << currentGear << endl;
        }

        void accelerate() {
            if(!isEngineOn){
                cout << brand << " " << model << ": cannot accelerate! engine is off" << endl;
            }
            currentSpeed += 10;
            cout << brand << " " << model << ": is accelerated to " << currentSpeed << endl;
        }

         //overriding and overloading accelerate at the same time.
        void accelerate(int speed){
            if(!isEngineOn){
                cout << brand << " " << model << ": cannot accelerate! engine is off" << endl;
            }
            else{
                currentSpeed += speed;
                cout << brand << " " << model << ": accelerating! current speed is " << currentSpeed << endl;
            }
        }

        void brake() {
            if(!isEngineOn){
                cout << brand << " " << model << ": cannot brake! engine is off" << endl;
            }
            else{
                currentSpeed -= 10;
                cout << brand << " " << model << ": braking! current speed is " << currentSpeed << endl;
            }
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
                cout << brand << " " << model << ": cannot accelerate! engine is off" << endl;
            }
            else{
                currentSpeed += 10;
                cout << brand << " " << model << ": accelerating! current speed is " << currentSpeed << endl;
            }
        }

        void accelerate(int speed){
            if(!isEngineOn){
                cout << brand << " " << model << ": cannot accelerate! engine is off" << endl;
            }
            else{
                currentSpeed += speed;
                cout << brand << " " << model << ": accelerating! current speed is " << currentSpeed << endl;
            }
        }

        void brake() {
            if(!isEngineOn){
                cout << brand << " " << model << ": cannot brake! engine is off" << endl;
            }
            else{
                currentSpeed -= 10;
                cout << brand << " " << model << ": braking! current speed is " << currentSpeed << endl;
            }
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