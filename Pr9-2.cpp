/*
Imagine you are tasked with developing a simple banking system for a local financial institution. The
bank has observed an increase in customer complaints regarding unclear transaction records and
unhandled errors during operations. They want a robust software module to manage bank accounts
efficiently while maintaining a log of transactions.
As a software developer, your job is to create a banking system with the following features:
1. A way to represent individual bank accounts, including the ability to manage their balances.
2. Secure methods to deposit and withdraw funds.
3. An error-handling mechanism to address invalid operations, such as attempting to withdraw more
than the account's current balance.
4. A feature that logs every function call when an error occurs to provide insights into the issue.
The bank also insists on maintaining a history of transactions using basic data structures without
relying on advanced libraries or containers. Design and implement a banking system that fulfills the
above requirements. 
*/

#include<iostream>
#include<stdexcept>
using namespace std;
    
class BankAccount {
    double Balance;
public:

    BankAccount(double amt) {
        if(amt<0) 
        throw invalid_argument("Balance must be positive!");

        Balance = amt;
    }

    void Withdraw(double amount) {
        if(amount<=0) 
        throw invalid_argument("Amount must be positive!");

        if(Balance-amount<0)
        throw logic_error("Not enough Balance for Withdrawal!");

        Balance-=amount;
        cout<<"\nMade by 24ce012 Tirth Bhatt"<<"\nWithdrew Rs. "<<amount<<" succesfully!";
    }

    void Deposit(double amount) {
        if(amount<=0) 
        throw invalid_argument("Amount must be positive!");

        Balance+=amount;
        cout<<"\nDeposited Rs. "<<amount<<" succesfully!";
    }

    void Display() {
        cout<<"\nCurrent Balance: Rs. "<<Balance;
    }
};
    
int main() {
    try {
        BankAccount A(1000);
//Made by 24ce012 Tirth Bhatt
        A.Deposit(2000);
        A.Withdraw(5000);
        A.Display();
    } catch(invalid_argument& e) {
        cout<<"\n\nCaught Invalid Argument: "<<e.what();
    } catch(logic_error& e) {
        cout<<"\n\nCaught Logical Error: "<<e.what();
    }
    
    return 0;
}