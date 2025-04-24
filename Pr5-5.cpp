/*
A software development team is tasked with designing a system that can 
handle various geometric shapes and compute their areas in a flexible way. 
The challenge is to create a system that can easily extend to accommodate 
new types of shapes without altering the core functionality for each shape. 
To accomplish this, the system is designed with a base class called Shape, 
which includes a virtual function Area(). This function is meant to be 
overridden by each specific shape class to provide the correct formula for 
calculating the area.
The derived classes, Rectangle and Circle, each implement the Area() function 
with their own formulas: the Rectangle calculates the area using its length 
and width, while the Circle uses its radius. This structure allows the system 
to treat all shapes uniformly through a common interface, enabling easy 
extensibility. The goal is to use a single reference to the base class 
(Shape*) to calculate the area of any shape, regardless of its type. This 
approach makes the system more adaptable, as new shapes can be added later 
without disrupting existing code.
In managing a collection of shapes, there are two primary approaches: one 
method involves dynamically managing a collection of shapes, allowing for 
easy addition and removal of shapes, while the other relies on a static 
method that requires manually managing the size of the collection. Both 
approaches aim to store and manage the shapes effectively, with one allowing 
automatic resizing as needed while the other requires more manual handling.
Through this case study, the team will implement the base class Shape and 
the derived classes Rectangle and Circle, each with their own Area() function.
The students will gain a deeper understanding of polymorphism, inheritance, 
and memory management while working with different methods to store and 
manage the collection of shapes.
*/

#define _USE_MATH_DEFINES
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;
//Made by 24ce012 Tirth Bhatt
class Shape {
protected:
    double Area;
    virtual void CalculateArea() = 0;

    void Display() {
        cout<<"\nArea: "<<Area<<" sq. units"<<"\nMade by 24ce012 Tirth Bhatt";
    }
};
    
class Rectangle : public Shape {
    double Length, Width;
    
    void CalculateArea() override{
        Area = Length*Width;
    }
public:
    
    Rectangle(double l, double w) : Length(l), Width(w) { 
        CalculateArea();
        Display();
    }
};
//Made by 24ce012 Tirth Bhatt
class Circle : public Shape {
    double Radius;
    
    void CalculateArea() override{
        Area = M_PI*Radius*Radius;
    }
public:

    Circle(double r) : Radius(r) { 
        CalculateArea();
        Display();
    }
};
    
int main() {
    int choice=1;
    double a, b;
//Made by 24ce012 Tirth Bhatt
    while(1) {
        cout<<"\n\n-~Area Calculator~-"
            <<"\nMade by 24ce012 Tirth Bhatt"
            <<"\nEnter 1 to for area of Circle, 2 for area of Rectangle and 0 to Exit\n\nEnter choice: ";
        cin>>choice;
        
        if(choice==1) {
            cout<<"\nEnter Circle Radius: ";
            cin>>a;
            Shape* Shape = new Circle(a);
        } else if(choice==2) {
            cout<<"\nEnter Rectangle Length: ";
            cin>>a;
            cout<<"Enter Rectangle Width: ";
            cin>>b;
            Shape* Shape = new Rectangle(a, b);
        } else if(choice==0) {
            cout<<"\nExiting System made by 24ce012 Tirth Bhatt...\n\n";
            break;
        }
    }
    //Made by 24ce012 Tirth Bhatt
    return 0;
}