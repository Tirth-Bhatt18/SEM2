/*
A team of software developers was tasked with creating a graphical simulation 
where operations on 2D points play a crucial role. To facilitate this, they 
designed a class Point that encapsulates the coordinates 𝑥 and 𝑦. The class 
provides flexibility through overloaded operators to manipulate points 
efficiently. The unary operator - is overloaded to negate the coordinates of 
a point, while the binary operator + enables the addition of two points. 
Additionally, the equality operator == is overloaded to compare whether two 
points have identical coordinates.
The development process required performing various operations between multiple 
points. To manage these operations effectively, a mechanism was needed to track 
and potentially undo them. This challenge prompted two approaches: using a 
ready-made dynamic stack structure or building a custom stack implementation. 
By managing a sequence of operations in reverse, the stack-based design allowed 
for a systematic undo capability, crucial for simulations involving iterative adjustments.

class Point:
coordinate x and y
operator-  negate both coords
operator+  add
operator==  comparision
*/

#include<iostream>
using namespace std;
    
class Point {
    float x, y;
public:

    Point() : x(0), y(0) {} 
    Point(float a, float b) : x(a), y(b) {}
//Made by 24ce012 Tirth Bhatt
    void InputData(float a, float b) {
        x=a;
        y=b;
    }

    void DisplayData() {
        cout<<"(x,y) = ("<<x<<','<<y<<')';
    }

    Point operator-() {  // Point A = - Point B // B unchanged
        return Point(-x, -y);
    }
    
    Point operator+(Point A) {  // Point C = Point A + Point B // A & B unchanged
        return Point(x+A.x, y+A.y);
    }
    
    bool operator==(Point A) {  // if(Point A == Point B) // A & B unchanged
        if(x==A.x && y==A.y)
        return true;
        else
        return false;
    }
};
    //Made by 24ce012 Tirth Bhatt
int main() {
    
    int choice=1;
    float X, Y;
    Point A, B, C;

    while(choice==1) {
        cout<<"\n\nEnter Point A:-";
        cout<<"\nX coordinate of A: ";
        cin>>X;
        cout<<"Y coordinate of A: ";
        cin>>Y;
        A.InputData(X, Y);
        cout<<"\nEnter Poiny B:-";
        cout<<"\nX coordinate of B: ";
        cin>>X;
        cout<<"Y coordinate of B: ";
        cin>>Y;
        B.InputData(X, Y);

        cout<<"\nOutput:";
        C = A + B;
        cout<<"\nA + B = ";
        C.DisplayData();
        C = -B;
        cout<<"\n-B = ";
        C.DisplayData();
        C = -A;
        cout<<"\n-A = ";
        C.DisplayData();
        if(A==B)
        cout<<"\nPoint A is equal to Point B";
        else
        cout<<"\nPoint A is not equal to Point B";

        cout<<"\n\nDo you want to perform operations again on different Points?\nEnter 1 for yes and 0 for no: ";
        cin>>choice;
    }
    //Made by 24ce012 Tirth Bhatt
    return 0;
}