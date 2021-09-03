#include <iostream>
#include <string>

class Figure {
public:
    virtual double area() = 0;
    virtual ~Figure() {}
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

void task1() {
    Circle circle(2);
    std::cout << "Circle area = " << circle.area() << std::endl;
    Rectangle rectangle(3, 4);
    std::cout << "Rectangle area = " << rectangle.area() << std::endl;
    Square square(3);
    std::cout << "Square area = " << square.area() << std::endl;
    Rhombus rhombus(3, 4);
    std::cout << "Rhombus area = " << rhombus.area() << std::endl;
    /*
    Square square(3);
    Figure* figure = &square;
    std::cout << figure->area();
    */
}

class Car {
private:
    std::string c_company;
    std::string c_model;
public:
    Car(std::string company, std::string model) : c_company(company), c_model(model) {
        std::cout << "Car class. Company: " << c_company << ", model: " << c_model << std::endl;
    }
    ~Car() {
        std::cout << "~Car class delele obj" << std::endl;
    }
};

class PassengerCar : virtual public Car {
public:
    PassengerCar(std::string company, std::string model) : Car(company, model) {
        std::cout << "PassengerCar class. Company: " << company << ", model: " << model << std::endl;
    }
    ~PassengerCar() {
        std::cout << "~PassengerCar class delele obj" << std::endl;
    }
};

class Bus : virtual public Car {
public:
    Bus(std::string company, std::string model) : Car(company, model) {
        std::cout << "Bus class. Company: " << company << ", model: " << model << std::endl;
    }
    ~Bus() {
        std::cout << "~Bus class delele obj" << std::endl;
    }
};

class Minivan : public PassengerCar, public Bus {
public:
    Minivan(std::string company, std::string model) : Bus(company, model), PassengerCar(company, model), Car(company, model) {
        std::cout << "Minivan class. Company: " << company << ", model: " << model << std::endl;
    }
    ~Minivan() {
        std::cout << "~Minivan class delele obj" << std::endl;
    }
};

void task2() {
    Car car("BullS", "Drandel");
    PassengerCar passengercar("Amoe", "Mark1");
    Bus bus("Troleb", "Microm");
    Minivan minivan("Matrew", "Sidas");
}

class Fraction {
private:
    int f_numerator;
    int f_denominator;
public:
    Fraction(int numerator, int denominator) : f_numerator(numerator) {
        if (denominator != 0) {
            f_denominator = denominator;
        }
        else {
            std::cout << "Denominator can't be 0, the default value is set 1";
            f_denominator = 1;
        };
    }

};

int main() {

    //task1();
    //task2();
    Fraction fraction(1, 0);


    return 0;
}
