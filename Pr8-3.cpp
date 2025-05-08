/*
A financial analytics firm is designing a data processing system to filter out duplicate transaction IDs
from large datasets. The system must take an input list of integers, efficiently remove duplicates, and
display the unique values in an ordered manner. Given the need for high performance in handling
large datasets, the implementation must leverage efficient data structures that automatically
eliminate redundancy.
To achieve this, the system employs an associative container that inherently ensures uniqueness while
maintaining a sorted order. As integers are added, duplicate entries are automatically discarded,
eliminating the need for explicit duplicate-checking logic. Once the unique values are identified, they
are either displayed directly using iterators or converted back into a dynamically managed sequence
for further processing.
By utilizing iterators, the system efficiently traverses the filtered dataset, ensuring that unique
elements are accessed and displayed without additional computational overhead. 
*/

#include<iostream>
#include<set>
using namespace std;

class IDList {
    set<int> List;
public:
    IDList() {
        string input;
        cout<<"\nMade by 24ce012 Tirth Bhatt"<<"\n\nEnter your Dataset and enter # to end it:\n";
        cin>>input;
        while(input.compare("#")) {
            List.insert(stoi(input));
            input.clear();
            cin>>input;
        }
    }

    void Display() {
        cout<<"\n\nDataset without duplicate entries is:";
        for(int id: List)
        cout<<endl<<id;
    }
};
    
int main() {
    //Made by 24ce012 Tirth Bhatt
    IDList L;
    L.Display();
    
    return 0;
}