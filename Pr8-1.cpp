/*
A data analytics firm is developing a tool to process numerical sequences efficiently. One of the key
requirements is to reverse a given sequence of integers while ensuring optimized performance using
modern C++ techniques. The system should allow users to input a sequence of numbers, process the
reversal using iterators, and display the transformed output.
To accomplish this, two approaches are explored. The first method leverages the built-in std::reverse()
function, which efficiently reverses elements within a dynamically managed sequence. The second
approach involves manually implementing the reversal using iterators, providing deeper insight into
how iterators navigate and modify data structures.
The system uses a dynamic storage mechanism to handle sequences of varying sizes efficiently.
Iterators facilitate traversal and modification, ensuring that elements are manipulated without direct
indexing. 
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
    
class NumberList {
    vector<int> List;
public:
    NumberList() {
        string input;
        cout<<"\nMade by 24ce012 Tirth Bhatt"<<"\n\nEnter your List and enter # to end it:\n";
        cin>>input;
        while(input.compare("#")) {
            List.push_back(stoi(input));
            input.clear();
            cin>>input;
        }
        cout<<"\nInputted "<<List.size()<<" elements in the list succesfully!";
    }

    void VecReverse() {
        reverse(List.begin(), List.end());

        cout<<"\n\n\nReversed List is:\n";
        for(int e : List) 
        cout<<endl<<e;
    }

    void HumanReverse() {
        int s=List.size(), temp;
        for(int i=0; i<s/2; i++) {
            temp = List[i];
            List[i] = List[s-i-1];
            List[s-i-1] = temp;
        }

        cout<<"\n\n\nHuman Reversed List is:\n";
        for(int e : List) 
        cout<<endl<<e;
    }
};//Made by 24ce012 Tirth Bhatt
    
int main() {
    
    NumberList L;
    L.HumanReverse();
    L.VecReverse();
    
    return 0;
}