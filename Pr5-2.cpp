/*
A mathematical research group aimed to create a software model for handling 
and performing operations on complex numbers efficiently. To achieve this, 
they designed a Complex class that encapsulates the real and imaginary parts 
of a complex number. The class supports essential operator overloading to 
enhance usability, including the addition and subtraction of complex numbers 
and custom input and output functionality through the << and >> operators. 
These overloaded operators ensure seamless arithmetic and user interaction 
with the system.
The task involves implementing this system and exploring its capabilities 
by performing various operations on complex numbers. Participants are expected 
to overload the specified operators and use them to add and subtract complex 
numbers, as well as to facilitate user-friendly input and output. Additionally, 
the solution encourages experimenting with managing collections of complex 
numbers to perform batch operations.

complex calculator:
real
imaginary
addition()
subtraction()
operator overloading
*/

#include<iostream>
using namespace std;
    
class Complex {
    float Real, Imaginary;
public:
    void InputData(float r, float i){
        Real=r;
        Imaginary=i;
    }

    Complex operator+(Complex &Input) {
        Complex Output;
        Output.Real = this->Real + Input.Real;
        Output.Imaginary = this->Imaginary + Input.Imaginary;
        
        return Output;
    }

    Complex operator-(Complex &Input) {
        Complex Output;
        Output.Real = this->Real - Input.Real;
        Output.Imaginary = this->Imaginary - Input.Imaginary;
        
        return Output;
    }
    
    Complex operator*(Complex &Input) {
        Complex Output;

        Output.Real = this->Real*Input.Real - this->Imaginary*Input.Imaginary;
        Output.Imaginary = this->Real*Input.Imaginary + this->Imaginary*Input.Real;
        
        return Output;
    }

    void Display() {
        cout<<Real<<" +i("<<Imaginary<<')';
        cout<<"\nMade by 24ce012 Tirth Bhatt\n";
    }
};
    
int main() {
    int choice=1;
    float Real, Img;
    Complex A, B, C;
//Made by 24ce012 Tirth Bhatt
    while(choice==1) {
        cout<<"\n\nEnter Complex Number A:-";
        cout<<"\nReal part of A: ";
        cin>>Real;
        cout<<"Imaginary part of A: ";
        cin>>Img;
        A.InputData(Real, Img);
        cout<<"\nEnter Complex Number B:-";
        cout<<"\nReal part of B: ";
        cin>>Real;
        cout<<"Imaginary part of B: ";
        cin>>Img;
        B.InputData(Real, Img);

        cout<<"\nOutput:";
        C = A + B;
        cout<<"\nA + B = ";
        C.Display();
        C = A - B;
        cout<<"\nA - B = ";
        C.Display();
        C = A*B;
        cout<<"\nA x B = ";
        C.Display();

        cout<<"\nMade by 24ce012 Tirth Bhatt\n";
        cout<<"\n\nDo you want to perform operations again on different complex numbers?\nEnter 1 for yes and 0 for no: ";
        cin>>choice;
    }
//Made by 24ce012 Tirth Bhatt
    return 0;
}