#include<iostream>
using namespace std;

void f(int n, int i=1)
{
    // n to 1
    if(i>n)
        return;
    cout<<i<<" ";
    f(n,i+1);
}

void b(string name, int i=5)
{
    // print string 5 times
    if(i<1)
        return;
    cout<<name<<" ";
    b(name,i-1);
}

void c(int n)
{
    // n to 1
    if(n < 1)
        return;
    cout<<n<<" ";
    c(n-1);
}

void d(int n)
{
    // 1 to 5 backtracking
    if(n<1)
        return;
    d(n-1);
    cout<<n<<" ";
}

void e(int n,int i=1)
{
    // 5 to 1 backtracking
    if(i > n)
        return;
    e(n,i+1);
    cout<<i<<" "; 
}

int main()
{
    string name="Prem";
    b(name);
    cout<<"\n";

    int n=5;
    f(n);
    cout<<"\n";

    c(n);
    cout<<"\n";

    d(n);
    cout<<"\n";

    e(n);
    cout<<"\n";
    return 0;
}
