#include<bits/stdc++.h>
using namespace std;

int oper(char ch)
{
	if(ch == '+' || ch=='-')
		return 1;
	else if(ch=='*' || ch=='/')
		return 2;
	else if(ch=='^')
		return 3;
	else 
		return 0;
}

string solve(string infix)
{
	stack<int> s;
	char c;
	string postfix="";
	for(int i=0;i<infix.length();i++)
	{
		c = infix[i];
		if(isalpha(c))
			postfix += infix[i];

		else if(c=='(')
			s.push(c);
		
		else if(c==')')
		{
			while(s.top()!='(')
			{
				postfix += s.top();
				s.pop();
			}
			s.pop();
		}

		else
		{
			while(!s.empty() && oper(infix[i]) <= oper(s.top())) {
                postfix += s.top();
                s.pop(); 
            }
            s.push(c);
        }
	}

	while(!s.empty()) {
			postfix += s.top();
			s.pop();
    	
	}
	return postfix;
}


int main()
{
	string infix="A*B+C/D";
	cout<<solve(infix);
	return 0;
}
