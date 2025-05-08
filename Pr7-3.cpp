/*
A small retail business is looking for a simple yet effective inventory management system to keep track
of its products. The system needs to support essential operations such as adding new items, viewing
the complete inventory, and searching for specific products. Since the inventory data should persist
across sessions, all operations must be performed using file storage. The business also requires an
efficient way to retrieve item details without unnecessary file reads.
To manage inventory, the system must allow employees to add new products by recording details
such as the item name, quantity, and price. These records should be appended to a file, ensuring that
previously stored data remains intact. When viewing inventory, the system should read the file
sequentially and display all stored items. Additionally, employees should be able to search for a
product by name, retrieving its details without manually scanning the entire file.
For implementation, two approaches are considered. One method processes file operations directly,
reading and searching line by line to retrieve item information efficiently. This minimizes memory
usage but requires re-reading the file for each search operation. An alternative approach loads
inventory data into a dynamically managed array, enabling faster searches and future enhancements
such as sorting and filtering without repeated file access.

inventory management 
add new item
view full inventory
view inventory of specific product

name qnty price
*/

#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
    
class Inventory {
    string filename;
    fstream InventoryFile;
public:
    Inventory(string name) : filename(name) { 
        InventoryFile.open(filename, ios::out | ios::trunc);
        InventoryFile.close(); 
        InventoryFile.open(filename, ios::app);
        if(!InventoryFile.is_open()) {
            cout<<endl<<"Unable to open file!";
            return;
        }
        InventoryFile.seekp(SEEK_END);
        InventoryFile<<"Inventory Management System\nName Quantity Price";
        InventoryFile.close(); 
    }

    void AddItem() {
        string name;
        int qnty;
        float price;
        cout<<"\nEnter Item Name: ";
        cin.ignore();
        getline(cin, name);
        cout<<"Enter Item Quantity: ";
        cin>>qnty;
        cout<<"Enter Item Price: ";
        cin>>price;

        InventoryFile.open(filename, ios::app);
        InventoryFile.seekp(SEEK_END);
        InventoryFile<<endl<<name<<" "<<to_string(qnty)<<" "<<to_string(price);
        InventoryFile.close();
        cout<<"\nItem added succesfully!";
    }    

    void ViewItem() {
        string sname, line, name, qnty, price;
        cout<<"\nEnter Item Name to view: ";
        cin>>sname;

        InventoryFile.open(filename, ios::in);
        while(getline(InventoryFile, line)) {
            stringstream words(line);
            words>>name;
            if(name!=sname) {
                continue;
            }

            words>>qnty;
            words>>price;
            cout<<"\nItem Found!\nName: "<<name<<"\nQuantity: "<<qnty<<"\nPrice: "<<price;
            InventoryFile.close();
            break;
        }
        if(name!=sname) {
            cout<<"\nItem Not Found!";
        }
    }

    void ViewInventory() {
        string line, name, qnty, price;
        int i=0;

        InventoryFile.open(filename, ios::in);
        getline(InventoryFile, line);
        getline(InventoryFile, line);
        cout<<"\nViewing Inventory:";
        while(getline(InventoryFile, line)) {
            stringstream words(line);
            words>>name;
            words>>qnty;
            words>>price;
            cout<<"\n\nItem "<<++i<<"\nName: "<<name<<"\nQuantity: "<<qnty<<"\nPrice: "<<price;
        }
        InventoryFile.close();
    }
};
    
int main() {

    Inventory InventoryManager("Pr7-3.txt");
    int choice;
    //Made by 24ce012 Tirth Bhatt
    while(choice!=0) {
        cout<<"\nMade by 24ce012 Tirth Bhatt"<<"\n\nInventory Management System:\nChoices:\n1. Add new Item\n2. View A Item\n3. View Full Inventory\n0. Exit System\nEnter choice: ";
        cin>>choice;

        switch(choice) {
        case 1:
            InventoryManager.AddItem();
            break;

        case 2:
            InventoryManager.ViewItem();
            break;

        case 3:
            InventoryManager.ViewInventory();
            break;

        default:
            break;
        }
    }
    cout<<"\nExiting System...";
    
    return 0;
}