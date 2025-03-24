

#include <iostream>
#include <string>

using namespace std;

class Device {
protected:
    string deviceID;
    string deviceType;
    double powerRating;
    bool isOn;

public:
    Device(string id, string type, double power) : deviceID(id), deviceType(type), powerRating(power), isOn(false) {}
    
    virtual void turnOn() { isOn = true; cout << deviceType << " [ID: " << deviceID << "] turned ON." << endl; }
    virtual void turnOff() { isOn = false; }
    virtual double calculatePowerUsage(int hours) const { return isOn ? powerRating * hours : 0; }
    
    friend ostream& operator<<(ostream& os, const Device& d) {
        os << d.deviceType << " [ID: " << d.deviceID << "] - Power: " << d.powerRating << "W, Status: " << (d.isOn ? "ON" : "OFF");
        return os;
    }
};

class Light : public Device {
public:
    Light(string id, string type, double power) : Device(id, type, power) {}
};

class Fan : public Device {
    int speed;
public:
    Fan(string id, string type, double power, int spd) : Device(id, type, power), speed(spd) {}
    void turnOn() override { isOn = true; cout << deviceType << " [ID: " << deviceID << "] turned ON at Speed " << speed << "." << endl; }
    double calculatePowerUsage(int hours) const override { return isOn ? powerRating * speed * hours : 0; }
};

class AirConditioner : public Device {
    double desiredTemp;
public:
    AirConditioner(string id, string type, double power, double temp) : Device(id, type, power), desiredTemp(temp) {}
    void turnOn() override { isOn = true; cout << deviceType << " [ID: " << deviceID << "] turned ON. Cooling to " << desiredTemp << "°C." << endl; }
    double calculatePowerUsage(int tempDifference) const { return isOn ? powerRating * (1 + (tempDifference / 100.0)) : 0; }
};

class SecuritySystem : public Device {
public:
    SecuritySystem(string id, string type, double power) : Device(id, type, power) {}
    void turnOn() override { isOn = true; cout << deviceType << " [ID: " << deviceID << "] activated." << endl; }
    double calculatePowerUsage(int hours) const override { return isOn ? powerRating * hours : 0; }
    
    friend void accessSecurityLogs(const SecuritySystem& secSys) {
        cout << "- Security Logs Accessed:\n- Intrusion Detected at 3:00 AM\n- System Reset Required" << endl;
    }
};

class User {
protected:
    string userID;
    string role;
    int accessLevel;
public:
    User(string id, string userRole, int level) : userID(id), role(userRole), accessLevel(level) {}
    void viewAccessibleDevices() const {
        cout << "User's " << userID << " - Accessible Devices:" << endl;
        if (accessLevel == 1) {
            cout << "- LED Light\n- Ceiling Fan\n- Split AC" << endl;
        } else {
            accessSecurityLogs(SecuritySystem("S001", "Home Alarm", 100));
        }
    }
};

int main() { 
    User user1("U001", "Regular User", 1);
    User user2("U002", "Maintenance Staff", 2);
     
    Light light1("L001", "LED Light", 10);
    Fan fan1("F001", "Ceiling Fan", 75, 3);
    AirConditioner ac1("AC001", "Split AC", 1500, 25);
    SecuritySystem secSys1("S001", "Home Alarm", 100);
     
    light1.turnOn();
    fan1.turnOn();
    ac1.turnOn();
    secSys1.turnOn();
     
    cout << "Power Consumption:" << endl;
    cout << "LED Light: " << light1.calculatePowerUsage(5) << " Watts" << endl;
    cout << "Ceiling Fan: " << fan1.calculatePowerUsage(3) << " Watts" << endl;
    cout << "Split AC: " << ac1.calculatePowerUsage(6) << " Watts" << endl;
    cout << "Security System: " << secSys1.calculatePowerUsage(24) << " Watts (Includes security checks)" << endl;
     
    user1.viewAccessibleDevices();
    user2.viewAccessibleDevices();
    
    return 0;
}
