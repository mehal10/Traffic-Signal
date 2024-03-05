#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

enum Trafficlight{RED,GREEN};

class Trafficsignal{
    private:
    Trafficlight currentlight;
    public:
    Trafficsignal(): currentlight(RED){}
    void switchlight(){
        if(currentlight==RED)
        currentlight=GREEN;
        else
        currentlight=RED;
    }
    
    Trafficlight getcurrentlight() const{
        return currentlight;
    }
};

class Intersection{
    private:
    Trafficsignal signal;
    public:
    void simulate(){
        while(true){
            cout<<"Traffic light is ";
            if(signal.getcurrentlight() == RED)
            cout << "RED" << endl;
            else
            cout << "GREEN" << endl;
            
            signal.switchlight();
            
            this_thread::sleep_for(chrono::seconds(100));
        }
    }
};
int main() {
    Intersection intersection;
    intersection.simulate();
    return 0;
}
