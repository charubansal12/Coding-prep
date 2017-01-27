#include<iostream>
#include<stack>
#include<stdlib.h>
using namespace std;
class Q
{
    private:
        stack<int> s1;
        stack<int> s2;
    public:
        void push(int x);
        int pop();
        int front();
        bool empty();
};
void Q::push(int x)
{
    if(s2.empty())
        s2.push(x);
    else
    {
        while(!s2.empty())
        {
            int tp=s2.top();
            s2.pop();
            s1.push(tp);
        }
        s1.push(x);
        while(!s1.empty())
        {
            int tp=s1.top();
            s1.pop();
            s2.push(tp);
        }
    }
}
int Q::pop()
{
   if(s2.empty())
        return -1;
   else
   {
       int tp=s2.top();
       s2.pop();
       return tp;
   }
}
int Q::front()
{
    if(s2.empty())
        return -1;
    else
        return s2.top();
}
bool Q::empty()
{
    if(s2.empty())
        return true;
    else
        return false;
}
int main()
{
    Q q1;
    int x;
    bool isem;
    int choice;
    do
    {
        cout<<"\t\t1.Push\n";
        cout<<"\t\t2.Pop\n";
        cout<<"\t\t3.Get front element\n";
        cout<<"\t\t4.Is queue empty?\n";
        cout<<"\t\t5.Exit\n";
        cout<<"Choice [1-5] ";
        cin>>choice;

        switch(choice)
        {
            case 1: cin>>x;
                    q1.push(x);
                    break;
            case 2: x=q1.pop();
                    cout<<"popped element : "<<x<<"\n";
                    break;
            case 3: x=q1.front();
                    cout<<x<<" is at the front of queue\n";
                    break;

            case 4: isem=q1.empty();
                    cout<<"Is the queue empty? "<<isem<<"\n";
                    break;

            case 5: cout<<"Exiting...";
                    exit(0);
                    break;
        }
    }while(choice!=5);

    return 0;
}
