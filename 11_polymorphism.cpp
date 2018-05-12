#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <functional>

/* Struct - more customized data type */

struct Shape{
    double length, width;
    Shape(double l = 1, double w = 1){
        length = l;
        width = w;
    }
    double Area(){
        return length * width;
    }
private:
    int id;
};

struct Circle : Shape{
    Circle(double width){
        this->width = width;
    }
    double Area(){
        return 3.14159 * std::pow((width/2), 2);
    }
};

int main() {
    Shape shape(10,10);
    std::cout << "Square Area : " << shape.Area() << "\n";
    Circle circle(10);
    std::cout << "Circle Area : " << circle.Area() << "\n";
    Shape rectangle(10,15);
    std::cout << "Rectangle Area : " << rectangle.Area() << "\n";

    return 0;
}

/* Friend */
class Customer{
private:
    friend class GetCustomerData;
    std::string name;
public:
    Customer(std::string name){
        this->name = name;
    }
};

class GetCustomerData{
public:
    static std::string GetName(Customer& customer){
        return customer.name;
    }
};

int main(){
    Customer tom("tom");
    GetCustomerData getName;
    std::cout << "Name : " << getName.GetName(tom) << "\n";
    
    return 0;
}

/* Polymorphism */

class Shape{
protected:
    double height;
    double width;
public:
    Shape(double length){
        height = length;
        width = length;
    }
    Shape(double h, double w){
        height = h;
        width = w;
    }
    virtual double Area(){
        return height * width;
    }
};

class Circle : public Shape{
public:
    Circle(double w) :
    Shape(w){
        
    }
    double Area(){
        return 3.14159 * std::pow((width / 2), 2);
    }
};

void ShowArea(Shape& shape){
    std::cout << "Area : " << shape.Area() << "\n";
}

int main(){
    Shape square(10,5);
    Circle circle(10);
    ShowArea(square);
    ShowArea(circle);
    return 0;
}

/* Abstract */

class Shape{
public:
    virtual double Area() = 0;
};

class Circle : public Shape{
protected:
    double width;
public:
    Circle(double w){
        width = w;
    }
    double Area() override{
        return 3.14159 * std::pow((width / 2), 2);
    }
};

class Rectangular : public Shape{
protected:
    double width, height;
public:
    Rectangular(double h, double w){
        height = h;
        width = w;
    }
    double Area() override final{ // with final, area can no longer overridden for subclass of Rectangular
        return width*height;
    }
};

void ShowArea(Shape& shape){
    std::cout << "Area : " << shape.Area() << "\n";
}

int main(){
    Rectangular rectangular(10,5);
    Circle circle(10);
    ShowArea(rectangular);
    ShowArea(circle);
    return 0;
}
