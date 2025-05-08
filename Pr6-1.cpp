/*
In a rapidly growing software development firm, a team of engineers is tasked with building a
lightweight, custom memory management system for handling dynamic datasets. The existing
framework lacks flexibility in managing arrays, often leading to inefficient memory usage and
performance bottlenecks. To address this, the engineers need to develop a solution that allows
seamless insertion and deletion of elements while ensuring efficient memory utilization.
The primary challenge is to design a structure that supports adding new data points dynamically at
the end of the dataset and removing specific elements based on their position. Since the system
operates in a resource-constrained environment, using standard template libraries is not an option,
and direct dynamic memory management must be implemented using pointers. The solution should
ensure that memory is allocated and deallocated appropriately to prevent leaks and unnecessary
overhead.
The development team must carefully decide on the structure of their implementation, defining how
data will be stored, accessed, and modified efficiently. They need to outline the appropriate class
design, determine essential data members, and define necessary member functions to handle the
operations effectively.
*/

#include<iostream>
using namespace std;

class DynamicArray {
    int* data;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for(int i=0; i<size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    DynamicArray() {
        size = 0;
        capacity = 2;
        data = new int[capacity];
    }

    void insert(int value) {
        if(size == capacity) {
            resize();
        }
        data[size] = value;
        size++;
    }

    void removeAt(int index) {
        if(index < 0 || index >= size) {
            cout<<"Invalid index."<<endl;
            return;
        }
        for(int i=index; i<size-1; i++) {
            data[i] = data[i+1];
        }
        size--;
    }

    void display() {
        if(size == 0) {
            cout<<"Array is empty."<<endl;
            return;
        }
        cout<<"Current array: ";
        for(int i=0; i<size; i++) {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

    ~DynamicArray() {
        delete[] data;
    }
};

int main() {
    DynamicArray arr;
    int choice, value, index;
//Made by 24ce012 Tirth Bhatt
    while(true) {
        cout<<"\nMade by 24ce012 Tirth Bhatt"<<"\n1. Insert value\n2. Delete by index\n3. Display array\n4. Exit\nEnter your choice: ";
        cin>>choice;

        if(choice == 1) {
            cout<<"Enter value to insert: ";
            cin>>value;
            arr.insert(value);
        }
        else if(choice == 2) {
            cout<<"Enter index to delete: ";
            cin>>index;
            arr.removeAt(index);
        }
        else if(choice == 3) {
            arr.display();
        }
        else if(choice == 4) {
            break;
        }
        else {
            cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    return 0;
}