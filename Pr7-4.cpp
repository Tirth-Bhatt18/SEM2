/*
An educational institution requires a system to generate well-structured student performance reports
from raw data stored in a file. The system should read student records, including their name, marks,
and grade, and present the information in a neatly formatted tabular format. Since the institution
handles large datasets, the report generation must be efficient, ensuring clear alignment and
readability while allowing for future enhancements such as sorting and filtering.
To achieve this, the system must first handle file input operations, reading student data while ensuring
error handling if the file is missing or inaccessible. The program should then format and display the
information in a structured manner, making use of a user-defined manipulator to align columns
properly. This ensures that names, marks, and grades are clearly visible in the report, regardless of
data length variations.
For implementation, two approaches are explored. The first method processes the data directly from
the file, formatting and displaying each entry without storing it in memory. This minimizes memory
usage but limits additional processing, such as sorting or filtering. The alternative approach
dynamically stores student records using a manually managed data structure, allowing further
modifications, such as sorting by marks or filtering based on grades, before presenting the final
formatted report.
*/

/*
A university administration is developing a system to display student marks in a structured and visually
appealing format. The goal is to ensure clarity in academic reports by properly aligning names and
scores while also demonstrating the use of currency formatting for tuition fees or other financial data.
To achieve this, built-in stream manipulators such as endl, setw, setfill, and setprecision must be used
to create a neatly formatted output.
The system first reads student names and their corresponding marks, ensuring that the data is aligned
in tabular form. Proper spacing between columns enhances readability, preventing misalignment
issues caused by varying name lengths or mark values. Additionally, numerical values must be
displayed with controlled decimal precision for consistency.
Beyond academic scores, the university also wants to format financial figures, such as tuition fees, in
a standardized manner. To achieve this, the system includes a user-defined manipulator, currency(),
which prepends a specified currency symbol (₹, $, etc.) before displaying monetary values. This custom
formatting ensures that financial data is both readable and professionally presented.
*/  

#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;
    
class StudentData {
    string filename;
    fstream StudentDataFile;
public:
    StudentData(string name) : filename(name) {}

    void ViewStudentData() {
        string line, name, m1, m2, m3;
        char grade;
        int i=0;

        StudentDataFile.open(filename, ios::in);
        if(!StudentDataFile.is_open()) {
            cout<<endl<<"Unable to open file!";
            return;
        }
        cout<<"\nMade by 24ce012 Tirth Bhatt"<<"\nViewing StudentData:";
        cout<<endl<<left<<setw(7)<<"Sr No."<<left<<setw(10)<<"Name"<<right<<setw(3)<<"M1"<<right<<setw(3)<<"M2"<<right<<setw(3)<<"M3"<<right<<setw(7)<<"Grade";
        while(getline(StudentDataFile, line)) {
            stringstream words(line);
            words>>name;
            words>>m1;
            words>>m2;
            words>>m3;
            words>>grade;
            cout<<endl<<left<<setw(7)<<++i<<left<<setw(10)<<name<<right<<setw(3)<<m1<<right<<setw(3)<<m2<<right<<setw(3)<<m3<<right<<setw(7)<<grade;
        }
        StudentDataFile.close();
    }
};
    
int main() {
//Made by 24ce012 Tirth Bhatt
    StudentData StudentDataManager("Pr7-4.txt");
    StudentDataManager.ViewStudentData();
    
    return 0;
}