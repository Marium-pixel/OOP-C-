/*Create a class for a stationary shop. The stationary shop maintains a list for all the items that it sells (hint: array of strings), and another list with the prices of the items (hint: array of prices).
Create a menu-driven program to:
1. Allow the shop owner to add the items and their prices.
2. Fetch the list of items
3. Edit the prices of the items
4. View all the items and their prices
Create a receipt that the shopkeeper can share with their customers. The receipt can only be created after the shopkeeper inputs the items and their amounts bought by the customer.*/

#include <iostream>
#include <string>
#include <iomanip> //lib For formatting output in the form of actual reciept
using namespace std;

class StationaryShop {
private:
    static const int MAX_ITEMS = 100;  
    string items[MAX_ITEMS];  //  item names
    double prices[MAX_ITEMS];          
    int itemCount;                     

public:
     
    StationaryShop() : itemCount(0) {}
 
    void addItem(const string& item, double price) {
        if (itemCount < MAX_ITEMS) {
            items[itemCount] = item;
            prices[itemCount] = price;
            itemCount++;
            cout << "Item added successfully!" << endl;
        } else {
            cout << "Shop is full! Cannot add more items." << endl;
        }
    }
 
    void fetchItems() const {
        if (itemCount == 0) {
            cout << "No items available in the shop." << endl;
            return;
        }
        cout << "List of items:" << endl;
        for (int i = 0; i < itemCount; ++i) {
            cout << i + 1 << ". " << items[i] << endl;
        }
    }
 
    void editPrice(int index, double newPrice) {
        if (index >= 1 && index <= itemCount) {
            prices[index - 1] = newPrice;
            cout << "Price updated successfully!" << endl;
        } else {
            cout << "Invalid item index!" << endl;
        }
    }
 
    void viewItemsAndPrices() const {
        if (itemCount == 0) {
            cout << "No items available in the shop." << endl;
            return;
        }
        cout << "Items and their prices:" << endl;
        cout << setw(20) << left << "Item" << setw(10) << right << "Price" << endl;
        cout << "----------------------------" << endl;
        for (int i = 0; i < itemCount; ++i) {
            cout << setw(20) << left << items[i] << setw(10) << right << fixed << setprecision(2) << prices[i] << endl;
        }
    }
 
    void generateReceipt() const {
        if (itemCount == 0) {
            cout << "No items available in the shop." << endl;
            return;
        }

        int quantities[MAX_ITEMS] = {0};  
        double totalCost = 0.0;

        cout << "Enter the quantities for each item:" << endl;
        for (int i = 0; i < itemCount; ++i) {
            cout << items[i] << ": ";
            cin >> quantities[i];
            totalCost += quantities[i] * prices[i];
        }
 
        cout << "\nReceipt:" << endl;
        cout << setw(20) << left << "Item" << setw(10) << right << "Quantity" << setw(10) << "Price" << setw(10) << "Total" << endl;
        cout << "---------------------------------------------" << endl;
        for (int i = 0; i < itemCount; ++i) {
            if (quantities[i] > 0) {
                cout << setw(20) << left << items[i]
                     << setw(10) << right << quantities[i]
                     << setw(10) << fixed << setprecision(2) << prices[i]
                     << setw(10) << quantities[i] * prices[i] << endl;
            }
        }
        cout << "---------------------------------------------" << endl;
        cout << setw(40) << right << "Total Cost: " << totalCost << endl;
    }
};

int main() {
    StationaryShop shop;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add item and price\n";
        cout << "2. Fetch list of items\n";
        cout << "3. Edit price of an item\n";
        cout << "4. View all items and their prices\n";
        cout << "5. Generate receipt\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string item;
                double price;
                cout << "Enter item name: ";
                cin.ignore(); // Clear input buffer
                getline(cin, item);
                cout << "Enter item price: ";
                cin >> price;
                shop.addItem(item, price);
                break;
            }
            case 2:
                shop.fetchItems();
                break;
            case 3: {
                int index;
                double newPrice;
                cout << "Enter item index: ";
                cin >> index;
                cout << "Enter new price: ";
                cin >> newPrice;
                shop.editPrice(index, newPrice);
                break;
            }
            case 4:
                shop.viewItemsAndPrices();
                break;
            case 5:
                shop.generateReceipt();
                break;
            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
