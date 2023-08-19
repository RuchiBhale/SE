#include <iostream>
using namespace std;

class Student
{
  string name;
  string contact_address;
  int roll_no, division;
  string cl,dob;
  string b_grp;
  string tel_no;
  string license_no;

public:
    friend void display(Student s1);
    Student ()
  {
    roll_no = 0;
    division = 0;
  }
   Student(string name, string cl, string b_grp, string contact_address, string license_no, string dob, int roll_no, string tel_no)
        {
          this->name = name;
          this->cl = cl;
          this->b_grp = b_grp;
          this->contact_address = contact_address;
          this->license_no = license_no;
          this->dob = dob;
          this->roll_no = roll_no;
          this->tel_no = tel_no;
        }
  Student(Student &s){
    name=s.name;
    b_grp=s.b_grp;
    contact_address=s.contact_address;
    cl=s.cl;
    dob=s.dob;
    tel_no=s.tel_no;
    license_no=s.license_no;
    roll_no=s.roll_no;
    division=s.division;
  }
  inline void accept ()
  {
    cout << "Enter the name of the student: ";
    cin >> name;
    cout << "\nEnter the roll no of the student: ";
    cin >> roll_no;
    cout << "\nEnter the class of the student: ";
    cin >> cl;
    cout << "\nEnter the division of the student: ";
    cin >> division;
    cout << "\nEnter the date of birth of the student: ";
    cin >> dob;
    cout << "\nEnter the blood group of the student: ";
    cin >> b_grp;
    cout << "\nEnter the contact address of the student: ";
    cin >> contact_address;
    cout << "\nEnter the telephone number of the student: ";
    cin >> tel_no;
    cout << "\nEnter the driving license number of the student: ";
    cin >> license_no;
  }
  friend void display (Student s1)
  {
    cout << s1.name << "\t" << s1.roll_no << "\t" << s1.cl << "\t" << s1.division<<"\t"
    << "\t" << s1.dob << "\t" <<s1.b_grp << "\t"<<"\t"<<s1.contact_address <<
      "\t" << s1.tel_no << "\t"<<"\t"<< s1.license_no << endl;
  }

};

int main ()
{
  int n;
  cout << "Enter the number of students";
  cin >> n;

  Student* s2=new Student[n];

//Student s2;
  for (int i = 0; i < n; i++)
    {
      s2[i].accept();
    }
  cout <<
    "Name\tRoll No\tClass\tDivision\tDOB\tBlood Group\tAddress\tTelephone number\tLicense Number\n";
  for (int i = 0; i < n; i++)
    {

      display(s2[i]);
      cout << "\n";
    }
  return 0;
}


