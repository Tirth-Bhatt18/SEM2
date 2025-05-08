/*
A software development team requires a lightweight directory management system to efficiently
organize project files. The system should allow users to create folders, add files to specific folders, and
display the directory structure in an organized manner.
Each folder serves as a unique entry, mapping to a list of associated files, ensuring structured storage
and easy retrieval. A hierarchical mapping approach is used, where folder names act as keys, and
dynamically resizable sequences store the corresponding filenames.
The system provides essential functionalities, including adding new folders, appending files to existing
folders, and displaying the complete directory structure. To enhance accessibility, folder names are
sorted alphabetically, allowing users to quickly locate specific folders and their contents. Iterators are
used for efficient traversal and structured display of data. This approach ensures optimized
performance, even for large datasets, while maintaining a logical and organized hierarchy.
*/

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
    
class FileManager {
    map<string, vector<string>> Folders;
public:
    void AddFolder() {
        string name;
        cout<<"\nEnter Folder Name: ";
        cin.ignore();
        getline(cin, name);
        Folders[name];
        cout<<"Folder Added Succesfully!";
    }

    void AddFile() {
        if(Folders.empty()) {
            cout<<"\nFile Management System is Empty!";
            return;
        }

        string filename, folname;
        cout<<"\nEnter folder name: ";
        cin.ignore();
        getline(cin, folname);

        auto find = Folders.find(folname);
        if(find == Folders.end()) {
            cout<<"\nNo such Folder found!";
            return;
        }

        cout<<"\nEnter file name to add: ";
        cin.ignore();
        getline(cin, filename);
        Folders[folname].push_back(filename);
        cout<<"File Added Succesfully!";
    }

    void Display() {
        if(Folders.empty()) {
            cout<<"\nFile Management System is Empty!";
            return;
        }

        cout<<"\nFolders & Files:";
        for(auto &fol : Folders) {
            sort(fol.second.begin(), fol.second.end());
            cout<<endl<<"|---"<<fol.first;
            for(string &file : fol.second) {
                cout<<endl<<"    |---"<<file;
            }
        }
    }
};
    
int main() {
    
    FileManager FileManagement;
    int choice=1;

    while(choice!=0) {
        cout<<"\nMade by 24ce012 Tirth Bhatt"<<"\n\nFile Management System:\nChoices:\n1. Add new Folder\n2. Add new File in a Folder\n3. View Existing Files\n0. Exit System\nEnter choice: ";
        cin>>choice;
//Made by 24ce012 Tirth Bhatt
        switch(choice) {
        case 1:
            FileManagement.AddFolder();
            break;

        case 2:
            FileManagement.AddFile();
            break;

        case 3:
            FileManagement.Display();
            break;

        default:
            break;
        }
    }
    cout<<"\nExiting System...";
    
    return 0;
}