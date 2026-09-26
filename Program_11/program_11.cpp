#include <iostream>

class Shape {
public:
    virtual double area() const = 0;

    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}

    double area() const override {
        return length * width;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double givenBase, double givenHeight)
        : base(givenBase), height(givenHeight) {}

    double area() const override {
        return 0.5 * base * height;
    }
};

int main() {
    Rectangle rectangle(8.0, 4.0);
    Triangle triangle(6.0, 4.0);

    std::cout << "Rectangle Area: " << rectangle.area() << '\n';
    std::cout << "Triangle Area: " << triangle.area() << '\n';

    return 0;
}
