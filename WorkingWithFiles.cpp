#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class employee
{
    int empno;
    char name[23];
    float salary;

    public :
             void getdata();
             void putdata();
             int getempno();
};
int employee::getempno()
{
    return empno;
}
void employee::getdata()
{

    cout<<"Employee number : ";
    cin>>empno;
    fflush(stdin);
    cout<<"Employee name : ";
    gets(name);
    fflush(stdin);
    cout<<"Salary : ";
    cin>>salary;
}
void employee::putdata()
{
    cout<<"Employee number : "<<empno<<"\n";
    cout<<"Employee name : ";
    puts(name);
    //cout<<"\n";
    cout<<"Salary : "<<salary;
}
void newemployee()
{
    fstream f1("employee.dat",ios::binary|ios::out|ios::app);
    employee emp;
    emp.getdata();
    f1.write((char *)&emp,sizeof(emp));
    f1.close();
}
void display()
{
    fstream f1("employee.dat",ios::binary|ios::in);
    employee emp;
    f1.read((char *)&emp,sizeof(emp));
          emp.putdata();
    f1.close();
}
void del()
{
    fstream f1("employee.dat",ios::binary|ios::in);
    fstream f2("temporary.dat",ios::binary|ios::out);

    employee emp;
    f1.seekg(0,ios::beg);
    int eno,fnd;
    char confirm='y';
    cout<<"Empno to delete :";
    cin>>eno;
    fnd=0;
    while(f1.read((char *)&emp,sizeof(emp)))
    {
        if(eno==emp.getempno())
        {
            emp.putdata();
            fnd=1;
            cout<<"Delete ?";
            cin>>confirm;

            if(confirm=='n')
                f2.write((char *)&emp,sizeof(emp));
            else
                cout<<"Record has been deleted";
        }
        else
            f2.write((char *)&emp,sizeof(emp));
    }
    f1.close();
    f2.close();
    remove("employee.dat");
    rename("temporary.dat","employee.dat");
    if(fnd==0)
        cout<<"No record to delete";

}
void modify()
{
    fstream f1("employee.dat",ios::binary|ios::out|ios::in);
    employee emp;
    f1.seekg(0,ios::beg);
    int eno;
    cout<<"Empno to modify :";
    cin>>eno;
    int rec=0,fnd=0;
     while(f1.read((char *)&emp,sizeof(emp)))
     {
         rec++;
         if(eno==emp.getempno())
         {
             emp.putdata();
             fnd=1;
             cout<<"Input new data";
             emp.getdata();
             f1.seekg((rec-1)*sizeof(emp),ios::beg);
             f1.write((char *)&emp,sizeof(emp));
             cout<<"Record modified";
         }
     }
     f1.close();
     if(fnd==0)
        cout<<"No record exist";
}
int main()
{
    newemployee();
    //display();
    del();
    modify();
    return 0;
}
