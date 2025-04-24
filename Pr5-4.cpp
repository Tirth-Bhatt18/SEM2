/*
A team of developers is tasked with building a temperature conversion 
system for a weather application. To achieve this, the team creates two 
classes: Celsius and Fahrenheit. These classes handle the conversion 
between temperature units, with the ability to convert from Celsius to 
Fahrenheit and vice versa using type conversion. The team utilizes operator 
overloading to define the conversion operators for both classes, enabling 
seamless conversions between the two units.
The system also requires the ability to compare two temperature objects to 
check if they are equal. This is achieved by overloading the equality operator 
==, which compares the values of the temperatures in their respective units.
To ensure smooth processing of temperature conversions, the team needs to manage 
and store multiple converted temperature objects. Two approaches are considered 
for handling this task. The first approach involves using a dynamic data structure, 
a queue, to process the conversions in a first-in-first-out (FIFO) manner. 
Alternatively, a basic array is used to store the converted objects in a static manner.
*/

#include<iostream>
using namespace std;

class Fahrenheit;
    
class Celsius {
    float Temperature;
public:
    Celsius() : Temperature(0) {}

    Celsius(float f) : Temperature(f) {}

    float ReturnTemp() { return Temperature; }

    void operator=(Fahrenheit); // C=F C is calling obj and F is parameter

    bool operator==(Fahrenheit);
};
    //Made by 24ce012 Tirth Bhatt
class Fahrenheit {
    float Temperature;
public:
    Fahrenheit() : Temperature(0) {}

    Fahrenheit(float f) : Temperature(f) {}

    float ReturnTemp() { return Temperature; }

    void operator=(Celsius);

    bool operator==(Celsius);
};
    //Made by 24ce012 Tirth Bhatt
bool Celsius::operator==(Fahrenheit F) {
    float temp = F.ReturnTemp();
    temp = temp - 32;
    temp = temp*5;
    temp = temp/9;

    if(temp == Temperature)
    return true;
    else
    return false;
}

void Celsius::operator=(Fahrenheit F) {
    Temperature = F.ReturnTemp();
    Temperature = Temperature - 32;
    Temperature = Temperature*5;
    Temperature = Temperature/9;
}
    //Made by 24ce012 Tirth Bhatt
bool Fahrenheit::operator==(Celsius C) {
    float temp = C.ReturnTemp();
    temp = temp*9;
    temp = temp/5;
    temp = temp + 32;

    if(temp == Temperature)
    return true;
    else
    return false;
}

void Fahrenheit::operator=(Celsius C) {
    Temperature = C.ReturnTemp();
    Temperature = Temperature*9;
    Temperature = Temperature/5;
    Temperature = Temperature + 32;
}
        
int main() {
    int choice=1;
    float Temperature;
    //Made by 24ce012 Tirth Bhatt
    while(choice==1) {
        cout<<"\n\n~-Temperature Comparator-~\n\nEnter Temperature in Celsius: ";
        cin>>Temperature;
        Celsius C(Temperature);
        
        cout<<"\nEnter Temperature in Fahrenheit: ";
        cin>>Temperature;
        Fahrenheit F(Temperature);
        
        Celsius Cel;
        Cel=F;
        Fahrenheit Fah;
        Fah=C;
        
        cout<<endl<<fixed<<C.ReturnTemp()<<" ^C in Fahrenheit is "<<Fah.ReturnTemp()<<" ^F";
        cout<<endl<<endl<<F.ReturnTemp()<<" ^F in Celsius is "<<Cel.ReturnTemp()<<" ^C\n\nSo, ";
        
        if(C==F & F==C)
        cout<<"Celsius temperature is the same as Fahrenheit temperature";
        else
        cout<<"Celsius temperature is not the same as Fahrenheit temperature";
        
        cout<<"\n\nMade by 24ce012 Tirth Bhatt"
            <<"\nDo you want to perform operations again with different Temperatures?"
            <<"\nEnter 1 for yes and 0 for no: ";
        cin>>choice;
    }
    //Made by 24ce012 Tirth Bhatt
    
    return 0;
}