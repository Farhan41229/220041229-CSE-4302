#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Abstract Base Class SmartDevice
class SmartDevice {
protected:
    int deviceID;
    string brandName;
    double powerRating;

public:
    SmartDevice(int id, string brand, double power) : deviceID(id), brandName(brand), powerRating(power) {}
    virtual void diagnose() = 0;
    double getPowerRating() const { return powerRating; }
    virtual void displayInfo() const {
        cout << "Device ID: " << deviceID << ", Brand: " << brandName << ", Power Rating: " << powerRating << "W\n";
    }
};

// Derived Class ThermostatDevice
class ThermostatDevice : public SmartDevice {
protected:
    double temperatureMin, temperatureMax;
    string mode;

public:
    ThermostatDevice(int id, string brand, double power, double tempMin, double tempMax, string mod)
        : SmartDevice(id, brand, power), temperatureMin(tempMin), temperatureMax(tempMax), mode(mod) {}

    double calculatePowerConsumption(double hours) {
        return powerRating * hours;
    }

    void diagnose() override {
        cout << "Diagnosing Thermostat Device. Mode: " << mode << ", Temperature Range: " 
             << temperatureMin << "C to " << temperatureMax << "C.\n";
    }
};

// Derived Class SecurityCameraDevice
class SecurityCameraDevice : public SmartDevice {
protected:
    string resolution;
    double recordingHours;

public:
    SecurityCameraDevice(int id, string brand, double power, string res, double recHours)
        : SmartDevice(id, brand, power), resolution(res), recordingHours(recHours) {}

    double calculateDataUsage(double days) {
        return recordingHours * days;
    }

    void diagnose() override {
        cout << "Diagnosing Security Camera Device. Resolution: " << resolution 
             << ", Recording Hours per Day: " << recordingHours << " hours.\n";
    }
};

// Further Derived Class SmartThermostat from ThermostatDevice
class SmartThermostat : public ThermostatDevice {
private:
    bool remoteControlEnabled;

public:
    SmartThermostat(int id, string brand, double power, double tempMin, double tempMax, string mod, bool remote)
        : ThermostatDevice(id, brand, power, tempMin, tempMax, mod), remoteControlEnabled(remote) {}

    double calculatePowerConsumption(double hours) override {
        return powerRating * hours * (remoteControlEnabled ? 0.9 : 1); // assume 10% less if remote controlled
    }

    void diagnose() override {
        cout << "Diagnosing Smart Thermostat Device. Remote Control Enabled: " << (remoteControlEnabled ? "Yes" : "No") << "\n";
    }
};

// Multiple Inheritance Class HybridThermostat from ThermostatDevice and SecurityCameraDevice
class HybridThermostat : public ThermostatDevice, public SecurityCameraDevice {
private:
    double energySavingEfficiency;

public:
    HybridThermostat(int id, string brand, double power, double tempMin, double tempMax, string mod, 
                     string res, double recHours, double efficiency)
        : SmartDevice(id, brand, power), ThermostatDevice(id, brand, power, tempMin, tempMax, mod), 
          SecurityCameraDevice(id, brand, power, res, recHours), energySavingEfficiency(efficiency) {}

    double calculatePowerConsumption(double hours) override {
        return powerRating * hours * (1 - energySavingEfficiency / 100);
    }

    double calculateDataUsage(double days) {
        return SecurityCameraDevice::calculateDataUsage(days) + (temperatureMax - temperatureMin) * days;
    }

    void diagnose() override {
        cout << "Diagnosing Hybrid Thermostat Device with energy-saving efficiency of " << energySavingEfficiency << "%\n";
    }

    void displayInfo() const override {
        SmartDevice::displayInfo();
        cout << "Energy Saving Efficiency: " << energySavingEfficiency << "%\n";
    }
};

// Function to sort devices by power rating in descending order
void sort_devices_by_power(SmartDevice** devices, int n) {
    sort(devices, devices + n, [](SmartDevice* a, SmartDevice* b) {
        return a->getPowerRating() > b->getPowerRating();
    });
}

int main() {
    vector<SmartDevice*> devices;
    devices.push_back(new ThermostatDevice(1, "ThermoCo", 150, 18.0, 30.0, "Heating"));
    devices.push_back(new SecurityCameraDevice(2, "SecureCam", 80, "1080p", 12.0));
    devices.push_back(new SmartThermostat(3, "SmartThermo", 120, 16.0, 28.0, "Cooling", true));
    HybridThermostat* hybridThermo = new HybridThermostat(4, "HybridPro", 200, 15.0, 25.0, "Fan-only", "4K", 10.0, 25.0);
    
    devices.push_back(hybridThermo);

    cout << "Devices before sorting by power rating:\n";
    for (auto device : devices) {
        device->displayInfo();
    }

    sort_devices_by_power(devices.data(), devices.size());

    cout << "\nDevices after sorting by power rating:\n";
    for (auto device : devices) {
        device->displayInfo();
    }

    cout << "\nHybridThermostat device information:\n";
    hybridThermo->displayInfo();

    // Clean up
    for (auto device : devices) {
        delete device;
    }

    return 0;
}