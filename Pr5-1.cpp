/*
A software development team aimed to design a versatile utility that could 
perform basic arithmetic operations while demonstrating the concept of function 
overloading. This effort resulted in a class-based calculator system capable of 
handling various combinations of input types, such as integers and doubleing-point 
numbers. The system includes multiple overloaded add functions, each tailored to 
accept distinct input types and perform addition operations accordingly. This 
approach ensures the calculator is adaptable and provides consistent functionality 
regardless of the input types.
The case revolves around testing and validating the versatility of this calculator. 
Participants are expected to create instances of the calculator, invoke the appropriate 
overloaded functions for various input scenarios, and store the resulting values for 
further analysis. To organize and display these results, the system incorporates methods 
to sequentially process and present the outcomes.


function overloading: int and double input and output
calculator:
addition
*/

#include<iostream>
using namespace std;
    
class Calculator {
public:
//Made by 24ce012 Tirth Bhatt
    int Add(int a, int b) {
        return (a+b);
    }

    double Add(int a, double b) {
        return (a+b);
    }

    double Add(double a, int b) {
        return (a+b);
    }

    double Add(double a, double b) {
        return (a+b);
    }
};
    
int main() {
    
    Calculator C;

    cout<<"\nAdding int and int: 65 + 52 = "<<C.Add(65, 52);
    cout<<"\nAdding int and double: 6 + 5.2 = "<<C.Add(6, 5.2);
    cout<<"\nAdding double and int: 6.5 + 5 = "<<C.Add(6.5, 5);
    cout<<"\nAdding double and double: 6.5 + 5.2 = "<<C.Add(6.5, 5.2);
    cout<<"\nMade by 24ce012 Tirth Bhatt\n";
    
    return 0;
}