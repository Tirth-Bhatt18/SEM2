/*
A software development team is working on an advanced simulation system that involves hierarchical
object management. The system includes a base class that defines general behavior and derived
classes that introduce specialized functionality, including dynamic resource allocation. During testing,
the team encounters unexpected memory leaks when deleting objects through base class pointers,
raising concerns about proper resource management.
To investigate the issue, the team examines how object destruction works in an inheritance hierarchy.
They create a base class that serves as a foundation for derived classes, but they notice that when a
Base* pointer is used to delete a Derived object, the destructor of the derived class is not invoked.
This results in dynamically allocated resources remaining in memory, causing resource leakage.
To resolve this problem, the team explores the concept of virtual destructors. By marking the base
class destructor as virtual, they ensure that the destructor of the derived class is correctly called when
deleting an object through a base class pointer. This guarantees proper deallocation of dynamically
allocated resources, preventing memory leaks.
Since the project requires manual memory management, the team uses raw pointers and the new and
delete operators to allocate and release resources.
*/

#include<iostream>
using namespace std;

class Base {
public:
    Base() {
        cout<<"\nMade by 24ce012 Tirth Bhatt"<<"Base constructor called"<<endl;
    }
    virtual ~Base() {
        cout<<"Base destructor called"<<endl;
    }
};

class Derived : public Base {
private:
    int* data;
public:
    Derived() {
        data = new int[5];
        cout<<"Derived constructor called"<<endl;
    }
    ~Derived() {
        delete[] data;
        cout<<"Derived destructor called"<<endl;
    }
};
//Made by 24ce012 Tirth Bhatt
int main() {
    Base* ptr = new Derived();
    delete ptr;
    return 0;
}