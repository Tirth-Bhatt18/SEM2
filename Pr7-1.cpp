/*
A media research team is developing a tool to analyze word frequency 
in large textual datasets, such as news articles and research papers. 
The goal is to process a given paragraph, identify individual words, 
and count their occurrences while ensuring case-insensitive matching. 
Since the tool is intended for both constrained environments and 
high-performance systems, two different approaches are considered—one 
utilizing dynamic memory management and another relying on manually 
structured arrays.
The first challenge is reading an entire paragraph from the console 
as a single unformatted string. Once acquired, the text must be split 
into individual words, ensuring that uppercase and lowercase variations 
are treated as the same. To store and process words dynamically, the 
team designs mechanism using raw pointers and dynamic memory allocation, 
allowing the program to handle variable input sizes effectively.
In one approach, a dynamically allocated array is used to store words, 
with additional logic to count occurrences efficiently. The array expands 
as needed, ensuring that new words can be accommodated. The frequency 
counting is implemented manually by searching for existing words in the 
array and updating counts accordingly.

reduce temp variables
naming proper
*/

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
    
class WordFrequency {
    string Input; //input string
    vector<string> Word; //each word
    vector<int> WCount; //each word's freq
public:

    void Count(string s) {
        Input = s; //take input
        Calculate();
        Display();
    }

    void Calculate() {
        stringstream s(Input);
        string a, b;
        int i=0;
        while(s>>a) { //for every word in the input string (defined as seperated by space)
            b.clear();
            for(auto x:a) {
                if(x!=',' && x!='.' && x!='\n') { //remove extra symbols
                    b+=(char)tolower(x); //store the lowercase word without extra symbols in temp
                }
            }
            i=0;
            for(auto w:Word) {
                if(w.compare(b)==0) { //check if it already exists in count database
                    WCount[i]++; //if exixts, increment freq
                    break;
                }
                i++;
            }
            if(i>=Word.size()) { //if doesnt exist, add it with freq 1
                Word.push_back(b);
                WCount.push_back(1);
            }
        }
    }

    void Display() {
        for(int i=0; i<Word.size(); i++) {
            cout<<endl<<Word[i]<<"  --->  "<<WCount[i];
        }
    }
};
    
int main() {
    
    WordFrequency Word;
    string input, temp;

    cout<<"\nMade by 24ce012 Tirth Bhatt"<<"\nEnter your text: (Enter #### to stop)\n\n";
//Made by 24ce012 Tirth Bhatt
    getline(cin, temp);
    while(temp!="####") {
        input+=temp;
        getline(cin, temp);
    }

    cout<<"\nFrequency of each word is:\n";
    Word.Count(input);

    return 0;
}