/******************************************************************************

create a class Student 
having data members int rollNo, int age, char sex, name(char*),
map<string, int> containing marks of subjects (sort according to marks)
English, Maths, Science, History, Geography
create 10 students and add it to a vector.
 
sort the vector according to name.

*******************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Student
{

    int rno;
    int age;
    char sex;
    char *name = new char[80];
    
public:

    map<string,int> mp;
    
    void setData();
    void display();
    void modifyMarks(string sub_modify, int marks_modify);
    void find_student(vector<Student> &students);
    
    string getName() const
    {
        return name;
    }
};

void Student :: setData()
{
    cout<<"Enter Rollno : ";
    cin>>rno;
    cout<<"Enter age : ";
    cin>>age;
    cout<<"Enter sex : ";
    cin>>sex;
    cout<<"Enter Name : ";
    cin.ignore();
    cin.getline(name,80);

    cout<<"Enter subject name and marks of students : "<<endl;
    for(int i=0;i<2;i++)
    {
        string s;
        int n;
        cin>>s>>n;
        mp.insert(make_pair(s,n));
    }
    cout<<endl;
}

void Student :: display()
{
    cout<<endl;
    cout<<"Name    : "<<name<<endl;
    cout<<"Roll No : "<<rno<<endl;
    cout<<"Age     : "<<age<<endl;
    cout<<"Sex     : "<<sex<<endl;
        
    cout<<"Marks of the student"<<endl;
    map<string, int>::iterator it;
    for(it=mp.begin(); it!=mp.end(); it++)
    {
        cout<<it->first << " - "<< it->second<<endl;
    }
}

void Student :: modifyMarks(string sub_modify, int marks_modify)
{
    map<string, int>::iterator it;
    for(it=mp.begin(); it!=mp.end(); it++)
    {
        if(it->first == sub_modify)
        {
            it->second = marks_modify;
            cout<<endl<<"Marks modified";
        }
   }
}

void Student ::  find_student(vector<Student> &students)
{
    string nameofstudent, sub_modify;
    cout<<endl<<"Enter the name of the student : ";
    cin.ignore();
    getline(cin,nameofstudent);
    int marks_modify;
    
    int count = 0;
    for (auto &student : students)
    {
        if(student.getName()==nameofstudent)
        {
            count =1;
            cout<<"Enter the name of the subject : ";
            cin>>sub_modify;
            cout<<"Enter the ne marks : ";
            cin>>marks_modify;
            
            student.modifyMarks(sub_modify,marks_modify);
            break;
        }
    }
    if(count ==1)
    {
        for(int i=0;i<2;i++)
        {
            students[i].display();
        }
    }
    else
    {
        cout<<"Not found";
    }
}

bool compareByName(const Student& a, const Student& b)
{
    return a.getName()<b.getName();
}


int main()
{
    vector<Student> students;
    for(int i=0;i<2;i++)
    {
        Student s;
        s.setData();
        students.push_back(s);
        
    }
    sort(students.begin(), students.end(),compareByName);
    
    for(int i=0;i<2;i++)
    {
        
        students[i].display();
    }
    Student s1;
    s1.find_student(students);
}


