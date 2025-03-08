#include <iostream>
using namespace std;

#define MAX_ITEMS 10

class MenuItem {
private:
    string name;
    double price;

public:
    MenuItem() : name(""), price(0.0) {}
    MenuItem(string n, double p) : name(n), price(p) {}

    string getName() const { return name; }
    double getPrice() const { return price; }

    void display() const {
        cout << name << " - $" << price << endl;
    }
};

class Menu {
private:
    MenuItem items[MAX_ITEMS];
    int itemCount;

public:
    Menu() : itemCount(0) {}

    void addItem(const MenuItem& item) {
        if (itemCount < MAX_ITEMS) {
            items[itemCount] = item;
            itemCount++;
        } else {
            cout << "Menu is full! Cannot add more items.\n";
        }
    }

    void displayMenu() const {
        cout << "----- Menu -----\n";
        for (int i = 0; i < itemCount; i++) {
            cout << i + 1 << ". ";
            items[i].display();
        }
        cout << "----------------\n";
    }

    int getItemCount() const { return itemCount; }
    MenuItem getItem(int index) const { return items[index]; }
};

class Payment {
private:
    double amount;

public:
    Payment() : amount(0.0) {}
    Payment(double amt) : amount(amt) {}

    void display() const {
        cout << "Total Amount: $" << amount << endl;
    }
};

class Order {
private:
    MenuItem orderItems[MAX_ITEMS];
    int itemCount;
    Payment payment;

public:
    Order() : itemCount(0) {}

    void addItem(const MenuItem& item) {
        if (itemCount < MAX_ITEMS) {
            orderItems[itemCount] = item;
            itemCount++;
        } else {
            cout << "Order is full! Cannot add more items.\n";
        }
    }

    void finalizeOrder() {
        double total = 0;
        for (int i = 0; i < itemCount; i++) {
            total += orderItems[i].getPrice();
        }
        payment = Payment(total);
    }

    void displayOrder() const {
        cout << "----- Order Details -----\n";
        for (int i = 0; i < itemCount; i++) {
            orderItems[i].display();
        }
        payment.display();
        cout << "-------------------------\n";
    }
};

class RestaurantSystem {
private:
    Menu menu;

public:
    RestaurantSystem() {
        menu.addItem(MenuItem("Burger", 5.99));
        menu.addItem(MenuItem("Pizza", 8.99));
        menu.addItem(MenuItem("Pasta", 7.49));
    }

    void displayMenu() const {
        menu.displayMenu();
    }

    void placeOrder() {
        Order order;
        int choice;

        cout << "Select items (Enter -1 to finish):\n";
        menu.displayMenu();
        int totalItems = menu.getItemCount();

        while (true) {
            cout << "Enter item number (1-" << totalItems << "): ";
            cin >> choice;

            if (choice == -1) break;

            if (choice >= 1 && choice <= totalItems) {
                order.addItem(menu.getItem(choice - 1));
            } else {
                cout << "Invalid choice, try again.\n";
            }
        }

        order.finalizeOrder();
        order.displayOrder();
    }
};

int main() {
    RestaurantSystem restaurant;
    restaurant.displayMenu();
    restaurant.placeOrder();
    return 0;
}
