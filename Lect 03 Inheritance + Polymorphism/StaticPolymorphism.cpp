#include <iostream>
#include <string>

using namespace std;

/*
Static Polymorphism (Compile-time polymorphism) in real life says that
the same action can behave differently depending on the input parameters.
For example, a Manual car can accelerate by a fixed amount or by a
specific amount you request. In programming, we achieve this via method
overloading: multiple methods with the same name but different signatures.
*/

class ManualCar {
    private: 
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;

    public:
        ManualCar(string brand, string model){
            this -> brand = brand;
            this -> model = model;
            this -> isEngineOn = false;
            this -> currentSpeed = 0;
            this -> currentGear = 0;
        }

        void startEngine() {
            isEngineOn = true;
            cout << brand << " " << model << ": engine is start" << endl;
        }

        void stopEngine() {
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
            cout << brand << " " << model << ": engine is stop" << endl;
        }

        void accelrate(int speed){
            if(!isEngineOn){
                cout << brand << " " << model << ": engine is not started" << endl;
            }
            currentSpeed += speed;
            cout << brand << " " << model << ": current speed is -> " << currentSpeed << endl;
        }

        void brake(){
            currentSpeed -= 10;
            if(currentSpeed < 0) currentSpeed = 0;
            cout << brand << " " << model << ": brekes to -> " << currentSpeed << endl;
        }

        void shiftedGear(int gear){
            currentGear = gear;
            cout << brand << " " << model << ": gear shifted to -> " << currentGear << endl;
        }
};


// Main function
int main() {
    ManualCar* myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();
    myManualCar->accelrate(20);
    myManualCar->accelrate(40);
    myManualCar->brake();
    myManualCar->stopEngine();

    // Cleanup
    delete myManualCar;

    return 0;
}