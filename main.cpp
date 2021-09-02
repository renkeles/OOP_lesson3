#include <iostream>

class Figure{
public:
    virtual void area() = 0;
};

class Parallelogram : public Figure{
private:
    int p_length;
    int p_width;
public:
    Parallelogram(int length, int width) : p_length(length), p_width(width){}
};

class Circle : public Figure{
    double c_radius;
public:
    Circle(double radius) : c_radius(radius){}
    void area() override{
        std::cout << "Circle area = " << 2 * 3.1415 * c_radius << std::endl;
    }
};

class Rectangle : public Parallelogram{
public:
    Rectangle(int length, int width) : Parallelogram(length,width){}

    void area() override{
        std::cout << "Parallelogram area = " << Parallelogram << std::endl;
    }
};

class Square : public Parallelogram{
public:
    void area(){
        std::cout << "area" << std::endl;
    }
};

class Rhombus : public Parallelogram{
public:
    void area(){
        std::cout << "area" << std::endl;
    }
};


int main(){

    Parallelogram parallelogram(3,4);
    parallelogram.area();
    Circle circle(1);
    circle.area();

    return 0;
}
