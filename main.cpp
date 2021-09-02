#include <iostream>

class Figure{
public:
    virtual double area() = 0;
};

class Parallelogram : public Figure{
private:
    double p_length;
    double p_width;
public:
    Parallelogram(double length, double width = 0.0) : p_length(length), p_width(width){}
    double area() override{
        double area = 0;
        if(p_width == 0.0){
            area = p_length * p_length;
        }else{
            area = p_length * p_width;
        }
        return area;
    }
};

class Circle : public Figure{
    double c_radius;
public:
    Circle(double radius) : c_radius(radius){}
    double area() override{
        std::cout << "Circle area = " << 2 * 3.1415 * c_radius << std::endl;
    }
};

class Rectangle : public Parallelogram{
public:
    Rectangle(int length, int width) : Parallelogram(length,width){}
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
