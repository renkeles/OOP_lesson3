#include <iostream>
#include <string>
#include <cmath>

int NOD(int a, int b);
int NOK(int a, int b);

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

////////////////////////////////////////////////

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

////////////////////////////////////////////////

class Fraction {
private:
    int f_numerator;
    int f_denominator;
public:
    Fraction() {
        f_numerator = 1;
        f_denominator = 1;
    }

    Fraction(int numerator, int denominator) : f_numerator(numerator) {
        if (denominator != 0) {
            f_denominator = denominator;
        }
        else {
            std::cout << "Denominator can't be 0, the default value is set 1";
            f_denominator = 1;
        };
    }

    friend Fraction operator+(const Fraction& f1, const Fraction &f2);
    friend Fraction operator-(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator/(const Fraction& f1, const Fraction& f2);

    Fraction operator-() const;

    friend bool operator==(const Fraction& f1, const Fraction& f2);
    friend bool operator!=(const Fraction& f1, const Fraction& f2);
    friend bool operator< (const Fraction& f1, const Fraction& f2);
    friend bool operator<=(const Fraction& f1, const Fraction& f2);
    friend bool operator> (const Fraction& f1, const Fraction& f2);
    friend bool operator>=(const Fraction& f1, const Fraction& f2);

    int getNum() {
        return f_numerator;
    }

    int getDenom() {
        return f_denominator;
    }

};

Fraction operator+(const Fraction& f1, const Fraction& f2) {

    Fraction fr;
    if (f1.f_denominator == f2.f_denominator) {
        fr.f_numerator = f1.f_numerator + f2.f_numerator;
        fr.f_denominator = f1.f_denominator;
    }
    else {
        int nok = NOK(f1.f_denominator, f2.f_denominator);
        fr.f_numerator = ((nok / f1.f_denominator) * f1.f_numerator) + ((nok / f2.f_denominator) * f2.f_numerator);
        fr.f_denominator = nok;
    }
    return fr;
}

Fraction operator-(const Fraction& f1, const Fraction& f2) {

    Fraction fr;
    if (f1.f_denominator == f2.f_denominator) {
        fr.f_numerator = f1.f_numerator - f2.f_numerator;
        fr.f_denominator = f1.f_denominator;
    }
    else {
        int nok = NOK(f1.f_denominator, f2.f_denominator);
        fr.f_numerator = ((nok / f1.f_denominator) * f1.f_numerator) - ((nok / f2.f_denominator) * f2.f_numerator);
        fr.f_denominator = nok;
    }
    return fr;
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {
    Fraction fr;
    fr.f_numerator = f1.f_numerator * f2.f_numerator;
    fr.f_denominator = f1.f_denominator * f2.f_denominator;
    return fr;
}

Fraction operator/(const Fraction& f1, const Fraction& f2) {

    Fraction fr;
    fr.f_numerator = f1.f_numerator * f2.f_denominator;
    fr.f_denominator = f1.f_denominator * f2.f_numerator;
    return fr;
}

Fraction Fraction::operator-() const {
    return Fraction(-f_numerator, f_denominator);
}

bool operator==(const Fraction& f1, const Fraction& f2) {
    return (f1.f_numerator == f2.f_numerator && f1.f_denominator == f2.f_denominator);
}

bool operator!=(const Fraction& f1, const Fraction& f2) {
    return (f1.f_numerator != f2.f_numerator || f1.f_denominator != f2.f_denominator);
}

bool operator< (const Fraction& f1, const Fraction& f2) {
    if (f1.f_numerator != f2.f_numerator && f1.f_denominator == f2.f_denominator) return (f1.f_numerator < f2.f_numerator);
    if (f1.f_numerator == f2.f_numerator && f1.f_denominator != f2.f_denominator) return (f1.f_denominator > f2.f_denominator);
    int nok = NOK(f1.f_denominator, f2.f_denominator);
    return (nok / f1.f_denominator * f1.f_numerator) < (nok / f2.f_denominator * f2.f_numerator);
}

bool operator<=(const Fraction& f1, const Fraction& f2) {
    if (f1 == f2) return true;
    if (f1 <  f2) return true;
    return false;
}

bool operator> (const Fraction& f1, const Fraction& f2) {
    if (f1 != f2) {
        return !(f1 < f2);
    }
    else {
        return false;
    }

}

bool operator>=(const Fraction& f1, const Fraction& f2) {
    if (f1 == f2) return true;
    if (f1 >  f2) return true;
    return false;
}

int NOD(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        }
        else {
            b -= a;
        }
    }
    return a;
}

int NOK(int a, int b) {
    return abs(a * b) / NOD(a, b);
}

void task3() {
    Fraction fr1(7, 15);
    Fraction fr2(1, 2);
    Fraction fr3;
    fr3 = fr1 + fr2;
    std::cout << fr3.getNum() << "/" << fr3.getDenom() << std::endl;
    fr3 = fr1 - fr2;
    std::cout << fr3.getNum() << "/" << fr3.getDenom() << std::endl;
    fr3 = fr1 * fr2;
    std::cout << fr3.getNum() << "/" << fr3.getDenom() << std::endl;
    fr3 = fr1 / fr2;
    std::cout << fr3.getNum() << "/" << fr3.getDenom() << std::endl;

    std::cout << (-fr1).getNum() << "/" << fr1.getDenom() << std::endl;

    if (fr1 == fr2) std::cout << "fr1 == fr2" << std::endl;
    if (fr1 != fr2) std::cout << "fr1 != fr2" << std::endl;
    if (fr1 < fr2) std::cout << "fr1 <  fr2" << std::endl;
    if (fr1 > fr2) std::cout << "fr1 >  fr2" << std::endl;
    if (fr1 <= fr2) std::cout << "fr1 <= fr2" << std::endl;
    if (fr1 >= fr2) std::cout << "fr1 >= fr2" << std::endl;
}

////////////////////////////////////////////////

enum Suit{
    HEART,
    DIAMOND,
    CLUB,
    SPADE
};
enum Value{
    JOKER,
    ACE,
    KING,
    QUEEN,
    JACK,
    TEN,
    NINE,
    EIGHT,
    SEVEN,
    SIX
};

class Card{
private:
    Suit _suit;
    Value _value;
    bool _faceDown;
public:
    Card(Suit suit, Value value, bool faceDown) : _suit(suit), _value(value), _faceDown(faceDown){}
    Suit getSuit(){
        return _suit;
    }
    Value getValue(){
        return _value;
    }
    bool getFaceDown(){
        return _faceDown;
    }

    bool setFaceDown(bool faceDown){
        _faceDown = faceDown;
    }

    bool Flip(Card &card){
        return card.setFaceDown(!card.getFaceDown());
    }
};

void task4(){
    Card card(DIAMOND, ACE, true);
    std::cout << card.getSuit() << " " << card.getValue() << " " << card.getFaceDown() << std::endl;
    card.Flip(card);
    std::cout << card.getSuit() << " " << card.getValue() << " " << card.getFaceDown() << std::endl;
    //card.Flip(card);
    //std::cout << card.getSuit() << " " << card.getValue() << " " << card.getFaceDown() << std::endl;
}

int main() {


    //task1();
    //task2();
    //task3();
    task4();

    return 0;
}
