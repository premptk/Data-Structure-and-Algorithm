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

string InfixtoPostfix(string infix)
{
	stack<int> s;
	char c;
	string postfix="";
	for(int i=0;i<infix.length();i++)
	{
		c = infix[i];
		if(c==' ')
			continue;

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


string solve(string infix)
{
	int l = infix.length();
	reverse(infix.begin(), infix.end());
	for(int i=0;i<l;i++)
	{
		if(infix[i]=='(')
		{	infix[i]=')';
			i++;
		}
		else if(infix[i]==')')
		{
			infix[i]='(';
			i++;
		}
	}
	string prefix = InfixtoPostfix(infix);
	reverse(prefix.begin(), prefix.end());
	return prefix;
}

int main()
{
	string infix="(A - B/C) * (A/K-L)";
	cout<<solve(infix);
	return 0;
}
