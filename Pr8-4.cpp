/*
An educational institution is developing a system to rank students based on their scores in an
examination. The goal is to efficiently store student names along with their respective scores, sort the
records in descending order based on scores, and display the ranked list. The system should be flexible
enough to handle varying numbers of students dynamically.
To achieve this, the system associates each student’s name with their score using a structured data
representation. A dynamically resizable sequence is chosen to store student records, allowing efficient
insertion and retrieval of entries. Each entry consists of a name-score pair, ensuring logical grouping
of related information.
Once the data is collected, a sorting operation is performed using a custom comparison function. By
leveraging an efficient sorting algorithm, the system ensures that students with the highest scores
appear at the top of the list. Iterators are then used to traverse and display the sorted data in a
structured format, highlighting rank-based ordering.
*/

#include<iostream>
#include<map>
using namespace std;
    
class StudentsData {
    multimap<int, string, greater<int>> Ranking;
public:
    StudentsData() {
        string name=" ";
        int marks;
        cout<<"\nMade by 24ce012 Tirth Bhatt"<<"\n\nInput Student Name and Marks (Enter ## to stop):\nName: ";
        cin>>name;
        while(name!="##") {
            cout<<"Marks: ";
            cin>>marks;
            Ranking.insert({marks, name});
            cout<<"Name: ";
            cin>>name;
        }
    }

    void Display() {
        int i=0;
        cout<<"\n\nRanking of "<<Ranking.size()<<" students is:";
        for(auto &M : Ranking) {
            cout<<endl<<++i<<") "<<M.second<<" -> "<<M.first;
        }
    }
};
    
int main() {
    //Made by 24ce012 Tirth Bhatt
    StudentsData DataBase;
    DataBase.Display();
    
    return 0;
}