/*
Imagine you're developing a financial calculator for a bank's system that 
allows users to calculate the ratio of two monetary values they input. This 
tool must be reliable, as it's part of a crucial decisionmaking process for 
loan eligibility. A bank customer is required to enter two values directly 
into the system:
1. The first value represents the total loan amount they wish to apply for.
2. The second value represents their annual income.
The system will compute and display the ratio of the loan amount to the income, 
which helps the bank assess the customer's loan-to-income ratio.
Major challenges that developer will face while developing the system would be, 
if the customer mistakenly enters non-numerical characters (e.g., "abc"), the 
system should handle the situation gracefully and prompt the user to correct 
their input. If the customer enters 0 as their annual income, the system must 
identify this issue and avoid performing a division that would lead to an 
invalid result.
*/

#include<iostream>
#include<stdexcept>
using namespace std;
    
class LTIRCalculator {
    double loan, income, LTIR;

    void Calculate() {
        if(income==0)
        throw logic_error("Income Can't be zero");

        LTIR = loan/income;
    }
public:

    LTIRCalculator() {
        cout<<"\n\nLoan to Income Ratio Calculator\n\nInput your Loan Amount: Rs. ";
        cin>>loan;
        cout<<"Input your Income Amount: Rs. ";
        cin>>income;

        if(loan<=0 || income<=0)
        throw invalid_argument("Value can't be Negative!");

        Calculate();
    }   
    
    void Display() {
        cout<<"\nMade by 24ce012 Tirth Bhatt"<<"\n\nYour Loan to Income Ratio is Rs. "<<LTIR;
    }
};
    
int main() {
    try {//Made by 24ce012 Tirth Bhatt
        LTIRCalculator CalC;
        CalC.Display();
    } catch(invalid_argument& e) {
        cout<<"\n\nCaught Invalid Argument: "<<e.what();
    } catch(logic_error& e) {
        cout<<"\n\nCaught Logical Error: "<<e.what();
    }

    return 0;
}