#include <iostream>

class Figure {
public:
    virtual double area() = 0;
};

class Parallelogram : public Figure {
private:
    double p_length;
    double p_width;
    double p_heigth;
public:
    Parallelogram(double length, double width = 0.0, double heigth = 0.0) : p_length(length), p_width(width), p_heigth(heigth) {}
    double area() override {
        double area = 0;
        if (p_heigth == 0.0) {
            if (p_width == 0.0) {
                area = p_length * p_length;
            }
            else {
                area = p_length * p_width;
            }
        }
        else {
            area = p_length * p_heigth;
        }

        return area;
    }
    friend class Rectangle;
};

class Circle : public Figure {
    double c_radius;
public:
    Circle(double radius) : c_radius(radius) {}
    double area() override {
        return 3.1415 * (c_radius * c_radius);
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(int length, int width) : Parallelogram(length, width) {}
};

class Square : public Parallelogram {
public:
    Square(int length) : Parallelogram(length) {}
};

class Rhombus : public Parallelogram {
public:
    Rhombus(double length, double heigth) : Parallelogram(length, length, heigth){}
};


int main() {

    Circle circle(1);
    std::cout << "Circle area = " << circle.area() << std::endl;
    Rectangle rectangle(3, 4);
    std::cout << "Rectangle area = " << rectangle.area() << std::endl;
    Square square(3);
    std::cout << "Square area = " << square.area() << std::endl;
    Rhombus rhombus(3, 4);
    std::cout << "Rhombus area = " << rhombus.area() << std::endl;

    return 0;
}
