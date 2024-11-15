#include<bits/stdc++.h>
using namespace std;

class SmartDevice{
protected:
    int DeviceID;
    string BrandName;
    double powerRating;
public:
    SmartDevice(int DeviceID, string BrandName, double powerRating){
        this->DeviceID = DeviceID;
        this->BrandName = BrandName;
        this->powerRating = powerRating;
    }
    virtual void diagnose() = 0;
    double getPowerRating() const { return powerRating; }
    virtual void displayInfo() const {
        cout << "Device ID: " << DeviceID << ", Brand: " << BrandName << ", Power Rating: " << powerRating << "W\n";
    }
};

class ThermostatDevice : public  SmartDevice {
protected:
    double temperatureMin;
    double temperatureMax;
    string mode;
public:
    ThermostatDevice(int id, string brand, double power, double tempMin, double tempMax, string mod)
        : SmartDevice(id, brand, power), temperatureMin(tempMin), temperatureMax(tempMax), mode(mod) {}

    virtual double calculatePowerConsumption(double hours){
        return powerRating * hours;
    }
    void diagnose(){
        cout<<"Diagnosing ThermostatDevice..."<<endl;
    }
    void displayInfo(){
        SmartDevice::displayInfo();
        cout<<"TemperatureMin: " << temperatureMin << ", TemperatureMax:"<<temperatureMax <<endl;
    }

};

class SecurityCameraDevice : public   SmartDevice {
protected:
    string resolution;
    double recordingHours;
public:
    SecurityCameraDevice(int id, string brand, double power, string res, double recHours)
        : SmartDevice(id, brand, power), resolution(res), recordingHours(recHours) {}
    double calculateDataUsage(double days){
        return recordingHours * days;
    }
    void diagnose(){
        cout<<"Diagnosing SecurityCameraDevice..."<<endl;
    }
    void displayInfo(){
        SmartDevice::displayInfo();
        cout<<"resolution: " << resolution << ", recordingHours:"<<recordingHours <<endl;
    }
};

class SmartThermostat : public ThermostatDevice {
protected: 
    bool remoteControlEnabled;
public:
    SmartThermostat(int id, string brand, double power, double tempMin, double tempMax, string mod, bool remote)
        : ThermostatDevice(id, brand, power, tempMin, tempMax, mod), remoteControlEnabled(remote) {}
    void diagnose(){
        cout<<"Diagnosing SmartThermostat..."<<endl;
    }
    double calculatePowerConsumption(double hours){
        return powerRating * hours * (remoteControlEnabled ? 0.9 : 1.0);
    }
    void displayInfo(){
        ThermostatDevice::displayInfo();
        cout<<"remoteControlEnabled: " << remoteControlEnabled<<endl;
    }
    
};


class HybridThermostat : public ThermostatDevice, public SecurityCameraDevice {
protected:
    double energySavingEfficiency;

public:
    HybridThermostat(int id, string brand, double power, double tempMin, double tempMax, string mod, 
                     string res, double recHours, double efficiency)
        : ThermostatDevice(id, brand, power, tempMin, tempMax, mod), 
          SecurityCameraDevice(id, brand, power, res, recHours), energySavingEfficiency(efficiency) {}

    double calculatePowerConsumption(double hours)  {
        return ThermostatDevice::powerRating * hours * energySavingEfficiency;
    }

    void displayinfo(){
        ThermostatDevice::displayInfo();
        cout<<"resolution: " << resolution << ", recordingHours:"<<recordingHours <<endl;
        cout<<"energySavingEfficiency: " << energySavingEfficiency<<endl;

    }


    void diagnose() override {
        cout << "Diagnosing Hybrid Thermostat Device with energy-saving efficiency of " << energySavingEfficiency << "%\n";
    }

    
};

void sort_devices_by_power(SmartDevice** devices, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (devices[j]->getPowerRating() < devices[j + 1]->getPowerRating()) {
                swap(devices[j], devices[j + 1]);
            }
        }
    }
}


int main() {
    // Create various smart device objects
    ThermostatDevice thermostat1(101, "ThermoBrand", 50.0, 18.0, 25.0, "Cool");
    SecurityCameraDevice camera1(102, "SecuroBrand", 10.0, "1080p", 24.0);
    SmartThermostat smartThermostat1(103, "SmartThermo", 45.0, 16.0, 24.0, "Heat", true);
    HybridThermostat hybridThermostat1(104, "HybridTech", 35.0, 15.0, 22.0, "Eco", "720p", 12.0, 0.85);

    // Array of SmartDevice pointers
    SmartDevice* devices[] = { &thermostat1, &camera1, &smartThermostat1,};
    int n = sizeof(devices) / sizeof(devices[0]);

    // Display information before sorting
    cout << "Devices before sorting by power rating:\n";
    for (int i = 0; i < n; ++i) {
        devices[i]->displayInfo();
        cout << endl;
    }

    // Sort devices by power rating
    sort_devices_by_power(devices, n);

    // Display information after sorting
    cout << "\nDevices after sorting by power rating:\n";
    for (int i = 0; i < n; ++i) {
        devices[i]->displayInfo();
        cout << endl;
    }

    return 0;
}