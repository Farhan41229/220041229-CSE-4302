#include<bits/stdc++.h>
using namespace std;

class Temperature {
    private:
        int temperature;
        int incrementsteps;

    public:
        Temperature() : temperature(0), incrementsteps(1) {}
        void setIncrementStep(int increment) { incrementsteps = increment; }
        int getTemperature() { return temperature; }
        void increment() { temperature += incrementsteps; }
        void resetTemperature() { temperature = 0; }
};


int main(){
    Temperature temp;
    temp.setIncrementStep(5);
    temp.increment();
    cout << "Temperature: " << temp.getTemperature() << endl;
    temp.resetTemperature();
    cout << "Temperature after reset: " << temp.getTemperature() << endl;
    return 0;
}