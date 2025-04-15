#include <iostream>
#include <string>

using namespace std;

class SmartDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() const = 0;
    virtual ~SmartDevice() {}
};

class LightBulb : public SmartDevice {
private:
    bool isOn;
    int brightness;

public:
    LightBulb() : isOn(false), brightness(0) {}

    void turnOn() override {
        isOn = true;
        brightness = 100; // Default brightness when turned on
    }

    void turnOff() override {
        isOn = false;
        brightness = 0;
    }

    void getStatus() const override {
        cout << "LightBulb Status: " << (isOn ? "On" : "Off") << ", Brightness: " << brightness << "%" << endl;
    }
};

class Thermostat : public SmartDevice {
private:
    bool isOn;
    double temperature;

public:
    Thermostat() : isOn(false), temperature(22.0) {} // Default temperature is 22°C

    void turnOn() override {
        isOn = true;
        temperature = 22.0; // Default temperature setting when turned on
    }

    void turnOff() override {
        isOn = false;
    }

    void getStatus() const override {
        cout << "Thermostat Status: " << (isOn ? "On" : "Off") << ", Temperature: " << temperature << "°C" << endl;
    }
};

int main() {
    LightBulb light;
    Thermostat thermostat;

    cout << "Initial statuses:\n";
    light.getStatus();
    thermostat.getStatus();

    cout << "\nTurning devices on...\n";
    light.turnOn();
    thermostat.turnOn();
    
    light.getStatus();
    thermostat.getStatus();

    cout << "\nTurning devices off...\n";
    light.turnOff();
    thermostat.turnOff();
    
    light.getStatus();
    thermostat.getStatus();

    return 0;
}
