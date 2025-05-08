/*
In a digital mapping application, a team of developers is working on a feature that allows objects to
be repositioned dynamically on a coordinate plane. The application requires precise control over the
movement of individual points representing user-defined markers. To achieve this, the team needs to
design a system that allows a point’s coordinates to be adjusted efficiently while maintaining a fluid
and chainable update mechanism.
To ensure seamless movement, the developers must implement a structure that allows each point to
shift by specified offsets in the x and y directions. Additionally, the solution should be designed in a
way that supports method chaining, enabling multiple transformations to be applied in a single
statement. This requires careful handling of object references, utilizing this pointer to return the
updated object.
Furthermore, the implementation must be optimized for direct memory management, ensuring that
objects are updated through pass-by-reference using pointers.
*/

#include<iostream>
using namespace std;

class Point {
    int x, y;

public:
    Point(int x=0, int y=0) {
        this->x = x;
        this->y = y;
    }

    Point* moveX(int dx) {
        x += dx;
        return this;
    }

    Point* moveY(int dy) {
        y += dy;
        return this;
    }

    void display() {
        cout<<"Point : ("<<x<<','<<y<<')'<<endl;
    }
};

int main() {
    int X, Y;
    cout<<"\nMade by 24ce012 Tirth Bhatt"<<"Enter X coordinate: ";
    cin>>X;
    cout<<"Enter Y coordinate: ";
    cin>>Y;

    Point* p = new Point(X, Y);
    p->display();
    
    int dx, dy;
    cout<<"Enter value to move in X direction: ";
    cin>>dx;
    cout<<"Enter value to move in Y direction: ";
    cin>>dy;

    //Made by 24ce012 Tirth Bhatt
    p->moveX(dx)->moveY(dy);
    p->display();

    delete p;
    return 0;
}