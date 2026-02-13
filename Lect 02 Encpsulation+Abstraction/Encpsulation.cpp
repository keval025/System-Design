#include <iostream>
#include <string>

using namespace std;

/*
Encapsulation says 2 things:
1. An Object's Characteristics and its behaviour are encapsulated together
within that Object.
2. All the characteristics or behaviours are not for everyone to access.
Object should provide data security.

We follow above 2 pointers about Object of real world in programming by:
1. Creating a class that act as a blueprint for Object creation. Class contain
all the characteristics (class variable) and behaviour (class methods) in one block,
encapsulating it together.
2. We introduce access modifiers (public, private, protected) etc to provide data
security to the class members.
*/


class SportsCar {
    private: 
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;
        
        //Introduce new variable to explain setters
        string tyreCompany;

    public: 
        SportsCar(string s, string m){
            this -> brand = s;
            this -> model = m;
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
            tyreCompany = "MRF";
        }

        int getSpeed(){
            return currentSpeed;
        }

        string getTyreCompany() {
            return TyreComny;
        }

        void setTyreCompany(string tyreCompany){
            this -> tyreCompany = tyreCompany;
        }

        void startEngine() {
            isEngine = true;
            cout << brand << " " << model << " : Engine starts with a roar!" << endl;
        }

        void shiftGear(int gear) {
            if(!isEngineOn) {
                cout << brand << " " << model << " : Engine is not start" << endl;
                return;
            }
            currentGear = gear;
            cout << brand << " " << model << " : Shifted to gear!" << endl;
        }

        void accelerate() {
            if(!isEngineOn) {
                cout << brand << " " << model << ": Engine is  off" << endl;
                return;
            }

            cuurentSpeed += 10;
            cout << brand << " " << model << ": acclerated to :" << currentGear << endl;
        }

        void break() {
            currentSpeed -= 10;
            if(currentSpeed < 0) currentSpeed = 0;
            cout << brand << " " << model << ": current speed is  ->" << currentSpeed << endl;
        }

        void stopEngine(){
            isEngine = false;
            currentSpeed = 0;
            currentGear = 0;
            cout << brand << " " << model << ": engine is off" << endl;
        }
        ~SportsCar() {}        
};

int main() {
    SportCar* mySportCar = new SportCar("Ford", "Mustang");

    mySportCar -> startEngine();
    mySportCar -> shiftGear(1);
    mySportCar -> acclerate();
    mySportsCar->shiftGear(2);
    mySportsCar->accelerate();
    mySportsCar->brake();
    mySportsCar->stopEngine();

    // //Setting arbitrary value to speed.
    // mySportsCar->currentSpeed = 500;

    // cout << "Current Speed of My Sports Car is set to " << mySportsCar->currentSpeed << endl;

    cout << "Current Speed of My Sports Car is " << mySportsCar->getSpeed() << endl;

    delete mySportsCar;    

    return 0;
}