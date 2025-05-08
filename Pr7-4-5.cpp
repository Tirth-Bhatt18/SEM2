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

#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;
    
class StudentData {
    string filename;
    fstream StudentDataFile;
public:
    StudentData(string name) : filename(name) {
        StudentDataFile.open(filename, ios::out | ios::trunc);
        StudentDataFile.close(); 
    }

    void AddStudentData() {
        
        string name, m1, m2, m3;
        char grade;
        float fees;

        cout<<"\nInput Student Name, Marks, Grade and Fees:\n";
        cin>>name>>m1>>m2>>m3>>grade>>fees;

        StudentDataFile.open(filename, ios::app);
        StudentDataFile.seekp(SEEK_END);
        if(!StudentDataFile.is_open()) {
            cout<<endl<<"Unable to open file!";
            return;
        }

        StudentDataFile<<endl<<name<<" "<<m1<<" "<<m2<<" "<<m3<<" "<<grade<<" "<<to_string(fees);
        StudentDataFile.close();
    }

    void ViewStudentData() {
        string line, name, m1, m2, m3;
        char grade;
        float fees;
        int i=0;

        StudentDataFile.open(filename, ios::in);
        if(!StudentDataFile.is_open()) {
            cout<<endl<<"Unable to open file!";
            return;
        }
        cout<<"\nMade by 24ce012 Tirth Bhatt"<<"\nViewing StudentData:";
        cout<<endl<<left<<setw(7)<<"Sr No."<<left<<setw(10)<<"Name"<<right<<setw(3)<<"M1"<<right<<setw(3)<<"M2"<<right<<setw(3)<<"M3"<<right<<setw(7)<<"Grade"<<left<<setw(7)<<setprecision(3)<<"Fees";
        while(getline(StudentDataFile, line)) {
            stringstream words(line);
            words>>name;
            words>>m1;
            words>>m2;
            words>>m3;
            words>>grade;
            words>>fees;
            cout<<endl<<left<<setw(7)<<++i<<left<<setw(10)<<name<<right<<setw(3)<<m1<<right<<setw(3)<<m2<<right<<setw(3)<<m3<<right<<setw(7)<<grade<<left<<setw(7)<<setprecision(3)<<fees;
        }
        StudentDataFile.close();
    }
};
    
int main() {

    StudentData StudentDataManager("Pr7-4.txt");
//Made by 24ce012 Tirth Bhatt
    StudentDataManager.AddStudentData();
    StudentDataManager.AddStudentData();
    StudentDataManager.AddStudentData();
    StudentDataManager.ViewStudentData();
    
    return 0;
}