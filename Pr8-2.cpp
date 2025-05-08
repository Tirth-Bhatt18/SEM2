/*
A digital publishing company is developing a tool to analyze text content for word frequency
distribution. This tool aims to help writers and editors understand the prominence of specific words
in an article, enabling them to refine their content for clarity and impact. The system should process
an input sentence, count occurrences of each unique word, and display the results in an organized
manner.
To achieve this, the system utilizes an associative container that maps words to their corresponding
frequencies. As the text is processed, each word is extracted and stored as a key, while its occurrence
count is maintained as the associated value. By leveraging iterators, the system efficiently traverses
the data structure, displaying each word along with its computed frequency.
The use of a dynamic mapping approach ensures that words are stored in an ordered manner, allowing
for fast retrieval and structured output. 
*/

#include<iostream>
#include<string>
#include<sstream>
#include<map>
using namespace std;
    
class WordFrequency {
    string Input; //input string
    map<string, int> WordFreq;
public:

    void Count(string s) {
        Input = s; //take input
        Calculate();
        Display();
    }

    void Calculate() {
        stringstream s(Input);
        string temp;
        while(s>>temp) {
            WordFreq[temp]++;
        }
    }

    void Display() {
        for(auto W : WordFreq) {
            cout<<endl<<W.first<<"  --->  "<<W.second;
        }
    }
};
    
int main() {
    //Made by 24ce012 Tirth Bhatt
    WordFrequency Word;
    string input;

    cout<<"\nMade by 24ce012 Tirth Bhatt"<<"\nEnter your text:\n\n";
    getline(cin, input);

    cout<<"\nFrequency of each word is:\n";
    Word.Count(input);

    return 0;
}