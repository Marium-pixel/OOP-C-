//Create a class called Smartphone with the following attributes:  Company
// Model  Display Resolution
// RAM
// ROM
// Storage
//Create getter and setter methods for your attributes. A smartphone has some specific actions that it can perform.For example:
//1. Make a phone call2. Send a message 3. Connect to the wifi 4. Browse the internet  Create different smartphone objects. Set their attributes using the setter functions and display
//their attributes after using the getter functions to fetch the attributes.


#include <iostream>
#include <string>
using namespace std;

class Smartphone {
private:
    string company;
    string model;
    string displayResolution;
    int ram;
    int rom;
    int storage;

public:
    void setCompany(const string& company) {
        this->company = company;
    }

    void setModel(const string& model) {
        this->model = model;
    }

    void setDisplayResolution(const string& resolution) {
        this->displayResolution = resolution;
    }

    void setRam(int ram) {
        this->ram = ram;
    }

    void setRom(int rom) {
        this->rom = rom;
    }

    void setStorage(int storage) {
        this->storage = storage;
    }

    string getCompany() const {
        return company;
    }

    string getModel() const {
        return model;
    }

    string getDisplayResolution() const {
        return displayResolution;
    }

    int getRam() const {
        return ram;
    }

    int getRom() const {
        return rom;
    }

    int getStorage() const {
        return storage;
    }

    void makePhoneCall() const {
        cout << "Making a phone call!" << endl;
    }

    void sendMessage() const {
        cout << " sending message!" << endl;
    }

    void connectToWifi() const {
        cout << "Connecting to Wi-Fi!" << endl;
    }

    void browseInternet() const {
        cout << "Browsing the internet!" << endl;
    }
};

int main() {
    Smartphone phone1;
    Smartphone phone2;

    phone1.setCompany("Apple");
    phone1.setModel("iPhone XX");
    phone1.setDisplayResolution("2532 x 1170 pixels");
    phone1.setRam(4);
    phone1.setRom(128);
    phone1.setStorage(256);

    phone2.setCompany(" Android");
    phone2.setModel("Galaxy A44");
    phone2.setDisplayResolution("2400 x 1080 pixels");
    phone2.setRam(8);
    phone2.setRom(128);
    phone2.setStorage(512);

    cout << "Phone 1 Details:" << endl;
    cout << "Company: " << phone1.getCompany() << endl;
    cout << "Model: " << phone1.getModel() << endl;
    cout << "Display Resolution: " << phone1.getDisplayResolution() << endl;
    cout << "RAM: " << phone1.getRam() << " GB" << endl;
    cout << "ROM: " << phone1.getRom() << " GB" << endl;
    cout << "Storage: " << phone1.getStorage() << " GB" << endl;

    phone1.makePhoneCall();
    phone1.sendMessage();
    phone1.connectToWifi();
    phone1.browseInternet();

    cout << "\nPhone 2 Details:" << endl;
    cout << "Company: " << phone2.getCompany() << endl;
    cout << "Model: " << phone2.getModel() << endl;
    cout << "Display Resolution: " << phone2.getDisplayResolution() << endl;
    cout << "RAM: " << phone2.getRam() << " GB" << endl;
    cout << "ROM: " << phone2.getRom() << " GB" << endl;
    cout << "Storage: " << phone2.getStorage() << " GB" << endl;

    phone2.makePhoneCall();
    phone2.sendMessage();
    phone2.connectToWifi();
    phone2.browseInternet();

    return 0;
}
