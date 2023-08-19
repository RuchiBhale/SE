
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Student{
    string name;
    int roll_no;
    int marks;
    public:
    void accept(){
        cout<<"Enter the name of the student: ";
        cin>>name;
        cout<<"Enter the roll number of the student: ";
        cin>>roll_no;
        cout<<"Enter the marks of the student: ";
        cin>>marks;
    }
    void display(){
        cout<<"DETAILS OF THE STUDENT ARE AS FOLLOWS\n";
        cout<<"Name: "<<name<<endl;
        cout<<"Roll No: "<<roll_no<<endl;
        cout<<"Marks: "<<marks<<endl;
    }

};
int main(){
    int n;
    cout<<"Enter the number of students: ";
    cin>>n;
    Student s[n];
    fstream f;
    f.open("Student_File.txt");
    for(int i=0;i<n;i++)
    {
        cout<<"\n Enter information of "<<i<<" "<<"student"<<endl;
        s[i].accept();
        f.write((char*)&s[i],sizeof s[i]);
    }
    f.close();
     f.open("Student_file.txt",ios::in);//open file in read mode
     for(int i=0;i<n;i++)
    {
        f.write((char*)&s[i],sizeof s[i]);
        s[i].display();
    }
    f.close();
    return 0;
}
