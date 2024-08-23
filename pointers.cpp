#include <iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;
class student
{
    public:    
    int rollno;
    char name[50];
    char fname[50];
    char degree[50];
    int semester;
    public:
    friend void remove_student();
    friend void edit_student();
    void accept()
    {
        cout<<endl<<"Enter Roll Number ";
        cin>>rollno;
        cout<<endl<<"Enter Student Name ";
        cin>>name;
        cout<<endl<<"Enter Father Name ";
        cin>>fname;
        cout<<endl<<"Enter Degree ";
        cin>>degree;
        cout<<endl<<"Enter Semester ";
        cin>>semester;
    }
    void display()
    {
        cout<<endl<<setw(5)<<rollno;
        cout<<setw(20)<<name;
        cout<<setw(20)<<fname;
        cout<<setw(15)<<degree;
        cout<<setw(3)<<semester;
    }
};
student s1; // we have created a global object that be accessed by any function
void add_student()
{
    s1.accept();
    fstream wr;
    wr.open("mystudents.txt",ios::app);
    wr.write((char *)&s1,sizeof(s1));
    wr.close();
    cout<<endl<<"Student Data written successfully ";
}
void remove_student()
{
    fstream rd;
    rd.open("mystudents.txt",ios::in);
    int size;
    rd.seekg(0,ios::end);
    size=rd.tellg();
    rd.seekg(0,ios::beg);
    int number_student=size/sizeof(s1);
    int rno;
    fstream wr;
    wr.open("temp.txt",ios::out);
    cout<<endl<<"Enter Roll Number to be searched & Removed";
    cin>>rno;
    for(int i=1;i<=number_student;i++)
    {
        rd.read((char *)&s1,sizeof(s1));
        if(s1.rollno==rno)
        {
            cout<<endl<<"Removed";
        }
        else
        {
            cout<<"writing roll number "<<s1.rollno;
            wr.write((char *)&s1,sizeof(s1));    
        }
    }
    wr.close();
    rd.close();
    remove("mystudents.txt");
    rename("temp.txt","mystudents.txt");

}

void edit_student()
{
    fstream rd;
    rd.open("mystudents.txt",ios::in);
    int size;
    rd.seekg(0,ios::end);
    size=rd.tellg();
    rd.seekg(0,ios::beg);
    int number_student=size/sizeof(s1);
    int rno;
    fstream wr;
    wr.open("temp.txt",ios::out);
    cout<<endl<<"Enter Roll Number to be searched & Removed";
    cin>>rno;
    for(int i=1;i<=number_student;i++)
    {
        rd.read((char *)&s1,sizeof(s1));
        if(s1.rollno==rno)
        {
            s1.accept();
            wr.write((char *)&s1,sizeof(s1));
        }
        else
        {
            wr.write((char *)&s1,sizeof(s1));    
        }
    }
    wr.close();
    rd.close();
    remove("mystudents.txt");
    rename("temp.txt","mystudents.txt");

}



void show_student()
{
    fstream rd;
    rd.o== NULL)
    {
        cout<<endl<<"Cannot open File";
    }
    else
    {
    int size;
    rd.seekg(-1,ios::end);
    size=rd.tellg();
    rd.seekg(0,ios::beg);
    
    cout<<endl<<setw(5)<<"RollNo";
    cout<<setw(20)<<"Name";
    cout<<setw(20)<<"Father Name";
    cout<<setw(15)<<"Degree";
    cout<<"Semester";
    cout<<endl<<"-----------------------------------------------------------------";
    for(int i=0;i<=size/sizeof(s1);i++)
    {
        rd.read((char *)&s1,sizeof(s1));
        s1.display();
    }
    }
}

class mark_attendance
{
    friend void view_attendance_date();
    int dd,mm,yy;
    int rollno;
    public:
    void init(int d,int m,int y,int r)
    {
        dd=d;
        mm=m;
        yy=y;
        rollno=r;
    }
    void display()
    {
        cout<<endl<<dd<<"-"<<mm<<"-"<<yy<<setw(5)<<rollno;
        fstream rd;
        rd.open("mystudents.txt",ios::in);
        rd.seekg(0,ios::end);
        int size=rd.tellg()/sizeof(s1);
        rd.seekg(0,ios::beg);
        for(int i=1;i<=size;i++)
        {
            rd.read((char *)&s1,sizeof(s1));
            if(rollno==s1.rollno)
            {
                cout<<setw(15)<<s1.name<<s1.fname<<s1.degree<<s1.semester;
            }
        }
    }

};
mark_attendance m1;
class attendance
{

    int dd,mm,yy;
    int arr[50];

    public:
    void accept()
    {
        int p;
        cout<<endl<<"Enter Date in DD MM YY";
        cin>>dd>>mm>>yy;
        cout<<endl<<"Enter Roll Numbers of present students followed by -1";
        int count=0;
        for(int i=0;i<=49;i++)
        {
           cin>>p;
           if(p==-1)
           {
            break;
           }     
           arr[i]=p;
           count++;
        }
        fstream wr;
        wr.open("attendance_data.txt",ios::app);
        for(int j=0;j<=count-1;j++)
        {
           m1.init(dd,mm,yy,arr[j]);     
           wr.write((char *)&m1,sizeof(m1));
        }
        wr.close();
    }
};

void view_attendance()
{
    fstream rd;
    rd.open("attendance_data.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(m1);
    cout<<endl<<"Number of Objects are "<<size;
    rd.seekg(0,ios::beg);
    for(int i=1;i<=size;i++)
    {
        rd.read((char *)&m1,sizeof(m1));
        m1.display();
    }

}

void view_attendance_date()
{
    int d,m,y;
    cout<<endl<<"Enter Date,Month,Year";
    cin>>d>>m>>y;
    fstream rd;
    rd.open("attendance_data.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(m1);
    cout<<endl<<"Number of Objects are "<<size;
    rd.seekg(0,ios::beg);
    for(int i=1;i<=size;i++)
    {
        rd.read((char *)&m1,sizeof(m1));
        if(m1.dd==d && m1.mm==m && m1.yy==y)
        {
        m1.display();
        }
    }

}




int main()
{
    int e=0;
    while (e==0)
    {
        cout<<endl<<"******************Welcome to Attendance Management**********";
        cout<<endl<<"\t\tPress 1 to Add New Student";
        cout<<endl<<"\t\tPress 2 to View all students";
        cout<<endl<<"\t\tPress 3 to Remove Student";
        cout<<endl<<"\t\tPress 4 to Update Student";
        cout<<endl<<"\t\tPress 5 Mark Bulk Attendance";
        cout<<endl<<"\t\tPress 6 to View Attendance";
        cout<<endl<<"\t\tPress 7 to View Attendace by Date";
        cout<<endl<<"\t\tPress 10 to Exit";
        cout<<endl<<"\t\tPress 0 to add those students who betrayed their friends";
        
        cout<<endl<<"**************************************************************";
        int choice;
        cin>>choice;
        if(choice==1)
        {
            add_student();
        }
        else if(choice==2)
        {
            show_student();
        }
        else if(choice==3)
        {
            remove_student();
        }
        else if(choice==4)
        {
            edit_student();
        }
        else if(choice==5)
        {
            attendance o1;
            o1.accept();
        }
        else if(choice==6)
        {
            view_attendance();
        }
        else if(choice==7)
        {
            view_attendance_date();
        }
        else
        {
            e=1;
            }
}
