#include <iostream>
#include <cmath>

class Point {
private:
    double x;
    double y;
public:
    Point(double x, double y) : x(x), y(y) {}

    double getX() const { return x; }

    double getY() const { return y; }

    void display() const { std::cout << "(" << x << ", " << y << ")"; }

    friend class Rectangle;
};


class Rectangle {
private:
    Point topLeft;
    Point bottomRight;
public:
    Rectangle(double x1, double y1, double x2, double y2)
        : topLeft(x1, y1), bottomRight(x2, y2) {}

    double getWidth() const {
        return std::abs(bottomRight.getX() - topLeft.getX());
    }

    double getHeight() const {
        return std::abs(bottomRight.getY() - topLeft.getY());
    }

    double getArea() const {
        return getWidth() * getHeight();
    }

    void display() const {
        std::cout << "Rectangle: ";
        topLeft.display();
        std::cout << " to ";
        bottomRight.display();
        std::cout << " | W=" << getWidth() << " H=" << getHeight()
                  << " Area=" << getArea();
    }

    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};


bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    return r1.getArea() == r2.getArea();
}


class ConstDemo {
private:
    int value;
public:
    ConstDemo(int v) : value(v) {}

    int getValue() const { return value; }

    void doubleValue() { value *= 2; }

    int constGetDouble() const { return value * 2; }
};


int main() {
    Point p(3.0, 4.0);
    std::cout << "Point: ";
    p.display();
    std::cout << std::endl;

    Rectangle r(0, 0, 4, 3);
    r.display();
    std::cout << std::endl;

    Rectangle r2(0, 0, 6, 2);
    std::cout << "Same size? " << (isSameSize(r, r2) ? "yes" : "no") << std::endl;

    ConstDemo cd(5);
    std::cout << "Value: " << cd.getValue() << std::endl;
    cd.doubleValue();
    std::cout << "After doubleValue: " << cd.getValue() << std::endl;
    std::cout << "constGetDouble: " << cd.constGetDouble() << std::endl;

    const ConstDemo constCd(9);
    std::cout << "Const object value: " << constCd.getValue() << std::endl;
    std::cout << "Const object constGetDouble: " << constCd.constGetDouble() << std::endl;

    return 0;
}
