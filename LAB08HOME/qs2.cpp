#include <iostream>
#include <string>

using namespace std;

const int MAX_PRODUCTS = 100; // Maximum number of products in the cart

class Product {
protected:
    string productID;
    double price;

public:
    Product(const string& id, double p) : productID(id), price(p) {}

    virtual double calculatePrice() = 0;

    virtual string applyDiscount(double discount) = 0;

    double getPrice() const {
        return price;
    }

    string getProductID() const {
        return productID;
    }
};

class Electronics : public Product {
public:
    Electronics(const string& id, double p) : Product(id, p) {}

    double calculatePrice() override {
        return price + (price * 0.15);
    }

    string applyDiscount(double discount) override {
        if (discount < 0) return "Error: Invalid discount.";
        if (discount > 0) price -= discount;
        return "Discount applied successfully.";
    }

    string applyDiscountPercentage(double percentage) {
        if (percentage < 0 || percentage > 100) return "Error: Invalid percentage.";
        double discount = (price * percentage) / 100;
        price -= discount;
        return "Percentage discount applied successfully.";
    }

    string applyBOGO() {
        return "Buy One Get One Free applied.";
    }
};

class Clothing : public Product {
public:
    Clothing(const string& id, double p) : Product(id, p) {}

    double calculatePrice() override {
        return price + (price * 0.05);
    }

    string applyDiscount(double discount) override {
        if (discount < 0) return "Error: Invalid discount.";
        if (discount > 0) price -= discount;
        return "Discount applied successfully.";
    }

    string applyDiscountPercentage(double percentage) {
        if (percentage < 0 || percentage > 100) return "Error: Invalid percentage.";
        double discount = (price * percentage) / 100;
        price -= discount;
        return "Percentage discount applied successfully.";
    }

    string applyBOGO() {
        return "Buy One Get One Free applied.";
    }
};

class ShoppingCart {
private:
    Product* products[MAX_PRODUCTS];
    int productCount;

public:
    ShoppingCart() : productCount(0) {}

    void addProduct(Product* product) {
        if (productCount < MAX_PRODUCTS) {
            products[productCount++] = product;
        } else {
            cout << "Cart is full. Cannot add more products." << endl;
        }
    }

    double calculateTotal() {
        double total = 0;
        for (int i = 0; i < productCount; ++i) {
            total += products[i]->calculatePrice();
        }
        return total;
    }

    ShoppingCart operator+(const ShoppingCart& other) {
        ShoppingCart newCart;
        for (int i = 0; i < productCount; ++i) {
            newCart.addProduct(products[i]);
        }
        for (int i = 0; i < other.productCount; ++i) {
            newCart.addProduct(other.products[i]);
        }
        return newCart;
    }

    void removeProduct(const string& productID) {
        for (int i = 0; i < productCount; ++i) {
            if (products[i]->getProductID() == productID) {
                for (int j = i; j < productCount - 1; ++j) {
                    products[j] = products[j + 1];
                }
                --productCount;
                return;
            }
        }
    }

    ShoppingCart operator*(double bulkDiscount) {
        ShoppingCart discountedCart;
        for (int i = 0; i < productCount; ++i) {
            products[i]->applyDiscount(bulkDiscount);
            discountedCart.addProduct(products[i]);
        }
        return discountedCart;
    }

    double operator/(int users) {
        if (users <= 0) return -1;
        return calculateTotal() / users;
    }

    void showCart() {
        for (int i = 0; i < productCount; ++i) {
            cout << "Product ID: " << products[i]->getProductID() 
                 << ", Price: $" << products[i]->calculatePrice() << endl;
        }
    }
};

int main() {
    Electronics phone("E001", 600);
    Clothing shirt("C001", 50);

    ShoppingCart cart1;
    cart1.addProduct(&phone);
    cart1.addProduct(&shirt);

    cout << "Cart 1 total: $" << cart1.calculateTotal() << endl;

    phone.applyDiscount(50);
    shirt.applyDiscountPercentage(10);

    cout << "Cart 1 total after discounts: $" << cart1.calculateTotal() << endl;

    ShoppingCart cart2;
    cart2.addProduct(new Electronics("E002", 800));
    
    ShoppingCart combinedCart = cart1 + cart2;
    cout << "Combined Cart total: $" << combinedCart.calculateTotal() << endl;

    combinedCart.removeProduct("C001");
    cout << "Combined Cart total after removing shirt: $" << combinedCart.calculateTotal() << endl;

    double splitPrice = combinedCart / 2;
    if (splitPrice >= 0) {
        cout << "Each user pays: $" << splitPrice << endl;
    } else {
        cout << "Error: Invalid number of users." << endl;
    }

    return 0;
}
