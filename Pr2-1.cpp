/*
Write a program to define a Rectangle class with the following:
Data Members:
o Length and Width (private)
Member Functions:
o SetDimensions(int l, int w) to Set the Length and Width.
o Area() to calculate and return the Area of the Rectangle.
o Perimeter() to calculate and return the Perimeter.
Tasks:
o Create multiple Rectangle objects.
o Initialize their Dimensions and display their Area and Perimeter.
*/

/*
A local construction company frequently deals with rectangular plots and structures of varying
Dimensions. To streamline their planning and estimation processes, the company requires a simple
System to manage and analyze rectangular shapes efficiently.
The System must be able to handle multiple Rectangles, each with distinct Dimensions. For each
Rectangle, the Length and Width need to be defined and stored securely. Additionally, the company
needs the ability to calculate two key metrics for any given Rectangle:
The Area, to estimate usable space or material coverage. The Perimeter, to estimate boundary Lengths
or material requirements for edges. To make this System functional, there should be a way to define
or Update the Dimensions of any Rectangle as required. The System should be capable of creating and
managing multiple Rectangle records, performing calculations for each, and displaying the results
clearly for analysis and planning purposes.
*/

#include<iostream>
using namespace std;
    
class Rectangle
{
    int Length, Width, Area, Perimeter; //class variables
    
public:

    void CalculateAnP()
    {
        Area = Length*Width;
        Perimeter = 2*(Length + Width);
    }

    void SetDimensions(int l, int w)
    {
        Length = l;
        Width = w;
        CalculateAnP();
    }

    void DisplayDetails() {
        cout<<"\nLength: "<<Length<<" units."
            <<"\nWidth: "<<Width<<" units."
            <<"\nArea: "<<Area<<" sq. units."
            <<"\nPerimeter: "<<Perimeter<<" units.";
    }
};
    
int main()
{
    Rectangle R[10];
    int Choice=1,Count=0;
    int Length,Width,Area,Perimeter;

    while(Choice>=1 && Choice<=3)
    {
        cout<<"\n\nChoices:\n1.Add Rectangle,\n2.Update Dimensions of Rectangle,\n3.View Existing Rectangles\n0.Exit System\nEnter your Choice: ";
        cin>>Choice; //choice based system

        switch (Choice)
        {
        case 1:
            cout<<"\nEnter Dimensions of New Rectangle "<<Count+1<<endl; //new rectangle
            cin>>Length>>Width;
            R[Count].SetDimensions(Length,Width); //input via user
            cout<<"\nNew Rectangle Added!";
            cout<<"\nTotal "<<Count+1<<" Rectangles in System";
            R[Count].DisplayDetails();
            Count++;
        break;

        case 2:
            int s;
            if(Count==0)
            {
                cout<<"\nNO Rectangles in System\nExiting...";
                break;
            }
            else
            {
                cout<<"Enter the Serial no. of the Rectangle of which to Update Dimensions: ";
                cin>>s; //update dimensions
                cout<<"\nEnter new Dimensions of Rectangle:\n";
                cin>>Length>>Width;
                R[s-1].SetDimensions(Length,Width);//changing dimensions using the same input function
                cout<<"\nRectangle Updated!";
                cout<<"\nNew Details of Rectangle "<<s;
                R[s-1].DisplayDetails();
            }
        break;

        case 3:
        
            cout<<"\n\nViewing Existing "<<Count<<" Rectangles";
            if(Count==0)
            {
                cout<<"\nNO Rectangles in System\nExiting...";
                break;
            }
            for(int j=0;j<Count;j++)
            {
                cout<<"\n\nRectangle "<<j+1; //list of all rectangles
                R[j].DisplayDetails();
            }
        break;
        
        default:
        break;
        }
    }

    return 0;
}
