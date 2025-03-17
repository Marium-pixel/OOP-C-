/* Picture an innovative design tool aimed at architects and graphic designers that allows for creating, manipulating, and analyzing various geometric shapes. The system is structured around a Shape class, which includes data members such as position, color, and an optional borderThickness. It provides functions like draw() for rendering, calculateArea() for area measurement, and calculatePerimeter() for perimeter computation. 
Derived classes such as Circle, Rectangle, Triangle, and Polygon introduce their own properties-for example, a Circle includes radius and center position, while a Rectangle includes width, height, and top-left corner position. Each derived class overrides draw(), calculateArea(), and calculate Perimeter() to handle their respective geometries. 
*/


#include <iostream>
using namespace std;
 
double customSqrt(double n) {
    double x = n;
    double y = 1;
    double e = 0.00001;
    while (x - y > e) {
        x = (x + y) / 2;
        y = n / x;
    }
    return x;
} 
double customAbs(double x) {
    return (x < 0) ? -x : x;
}

class Shape {
protected:
    string color;
    double borderThickness;

public:
    Shape(string col = "black", double border = 1.0)
        : color(col), borderThickness(border) {}

    virtual void draw() const = 0;
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
    double centerX, centerY;

public:
    Circle(double r, double x, double y, string col = "black", double border = 1.0)
        : Shape(col, border), radius(r), centerX(x), centerY(y) {}

    void draw() const override {
        cout << "Drawing Circle at (" << centerX << ", " << centerY
             << ") with radius " << radius << " and color " << color << "\n";
    }

    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }

    double calculatePerimeter() const override {
        return 2 * 3.14159 * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
    double topLeftX, topLeftY;

public:
    Rectangle(double w, double h, double x, double y, string col = "black", double border = 1.0)
        : Shape(col, border), width(w), height(h), topLeftX(x), topLeftY(y) {}

    void draw() const override {
        cout << "Drawing Rectangle at (" << topLeftX << ", " << topLeftY
             << ") with width " << width << " and height " << height
             << " and color " << color << "\n";
    }

    double calculateArea() const override {
        return width * height;
    }

    double calculatePerimeter() const override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
private:
    double x1, y1, x2, y2, x3, y3;

    double distance(double x1, double y1, double x2, double y2) const {
        return customSqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }

public:
    Triangle(double ax, double ay, double bx, double by, double cx, double cy, string col = "black", double border = 1.0)
        : Shape(col, border), x1(ax), y1(ay), x2(bx), y2(by), x3(cx), y3(cy) {}

    void draw() const override {
        cout << "Drawing Triangle with vertices (" << x1 << ", " << y1 << "), ("
             << x2 << ", " << y2 << "), (" << x3 << ", " << y3 << ") and color " << color << "\n";
    }

    double calculateArea() const override {
        return customAbs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
    }

    double calculatePerimeter() const override {
        return distance(x1, y1, x2, y2) + distance(x2, y2, x3, y3) + distance(x3, y3, x1, y1);
    }
};

class Polygon : public Shape {
private:
    static const int MAX_VERTICES = 10;
    double vertices[MAX_VERTICES][2];
    int numVertices;

    double distance(double x1, double y1, double x2, double y2) const {
        return customSqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }

public:
    Polygon(double verts[][2], int num, string col = "black", double border = 1.0)
        : Shape(col, border), numVertices(num) {
        for (int i = 0; i < numVertices; i++) {
            vertices[i][0] = verts[i][0];
            vertices[i][1] = verts[i][1];
        }
    }

    void draw() const override {
        cout << "Drawing Polygon with " << numVertices << " vertices and color " << color << "\n";
    }

    double calculateArea() const override {
        double area = 0.0;
        for (int i = 0; i < numVertices; i++) {
            int j = (i + 1) % numVertices;
            area += vertices[i][0] * vertices[j][1];
            area -= vertices[j][0] * vertices[i][1];
        }
        return customAbs(area) / 2.0;
    }

    double calculatePerimeter() const override {
        double perimeter = 0.0;
        for (int i = 0; i < numVertices; i++) {
            int j = (i + 1) % numVertices;
            perimeter += distance(vertices[i][0], vertices[i][1], vertices[j][0], vertices[j][1]);
        }
        return perimeter;
    }
};

int main() {
    Circle c(5, 0, 0, "red", 2.0);
    Rectangle r(10, 5, 2, 3, "blue", 1.5);
    Triangle t(0, 0, 5, 0, 2.5, 4, "green", 1.0);

    double polygonVertices[5][2] = {{0, 0}, {4, 0}, {4, 3}, {2, 5}, {0, 3}};
    Polygon p(polygonVertices, 5, "purple", 2.5);

    cout << "\n--- Drawing Shapes ---\n";
    c.draw();
    r.draw();
    t.draw();
    p.draw();

    cout << "\n--- Area Calculation ---\n";
    cout << "Circle Area: " << c.calculateArea() << "\n";
    cout << "Rectangle Area: " << r.calculateArea() << "\n";
    cout << "Triangle Area: " << t.calculateArea() << "\n";
    cout << "Polygon Area: " << p.calculateArea() << "\n";

    cout << "\n--- Perimeter Calculation ---\n";
    cout << "Circle Perimeter: " << c.calculatePerimeter() << "\n";
    cout << "Rectangle Perimeter: " << r.calculatePerimeter() << "\n";
    cout << "Triangle Perimeter: " << t.calculatePerimeter() << "\n";
    cout << "Polygon Perimeter: " << p.calculatePerimeter() << "\n";

    return 0;
}
