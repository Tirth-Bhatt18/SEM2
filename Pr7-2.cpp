/*
A data analysis firm is developing a tool to process large text 
files and extract key statistics, such as the total number of 
characters, words, and lines. This tool is essential for tasks 
like document indexing, text summarization, and data validation. 
Given the varying sizes of input files, the system must handle 
large datasets efficiently while ensuring error detection when 
files are missing or inaccessible.
To begin, the program needs to open a specified text file and 
process its contents line by line. If the file cannot be found 
or opened due to permission issues, the system should notify the 
user with an appropriate error message and safely terminate execution. 
Once the file is successfully accessed, the program will analyze its 
contents to count the total number of lines, extract words while 
handling different delimiters, and compute the total number of 
characters, including spaces and punctuation.
For handling this data, the team explores two approaches. One 
approach dynamically stores the lines in a manually managed array, 
processing the information without relying on built-in containers. 
This requires careful memory allocation and deallocation to avoid 
leaks. The alternative approach uses a dynamic structure to hold 
the lines in memory, allowing for efficient access and further 
analysis, such as searching or editing.
   . , ! & ( ) - + = _ / 
*/

#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
    
class Counter {
    fstream InputFile;
    unsigned int nlines, nwords, nchars;

    void Count() {
        string line;

        while(getline(InputFile, line, '.')) {
            stringstream word(line);
            string temp;
            
            nlines++;
            while(word>>temp) { nwords++; }
            nchars+=line.length();
        }
    }
public:

    Counter(string FileName) {
        InputFile.open(FileName, ios::in);
        if(!InputFile.is_open()) {
            cerr<<endl<<"Unable to open file!";
            return;
        }
        
        nlines=0;
        nwords=0;
        nchars=0;
        
        Count();

        InputFile.close();
    }
    
    void DisplayCount() {
        cout<<"\n\nNumber of lines: "<<nlines;
        cout<<"\nNumber of words: "<<nwords;
        cout<<"\nNumber of characters: "<<nchars;
        cout<<"\nMade by 24CE012 Tirth Bhatt\n\n";
    }

    ~Counter() { InputFile.close(); }
};
    
int main() {
    
    Counter Count("Input7-2.txt");

    Count.DisplayCount();
    
    return 0;
}