#include<iostream>
using namespace std;

// Functional
int RecSum(int n)
{
    if(n<1)
        return 0;
    return n + RecSum(n-1);
}

int fact(int n)
{
    if(n<2)
        return 1;
    return n*fact(n-1);
}


// Parameterized
int ParaSum(int n, int sum=0)
{
    if(n == 0)
        return sum;
    return ParaSum(n-1, sum+n);
}


int ParaFact(int n, int fact=1)
{
    if(n==1)
        return fact;
    return ParaFact(n-1, fact*n);
}


int main()
{
 // Recursion - Parameterized , Functional
    // Functional Recursion
    cout<<RecSum(10)<<endl;  
    cout<<fact(10)<<endl;

    // Parameterized Recursion
    cout<<ParaSum(10)<<endl;
    cout<<ParaFact(5)<<endl;
    return 0;
}
