#include<bits/stdc++.h>
using namespace std;

int solve(string postfix)
{
	stack<int> s;
	for(int i=0;i<postfix.length();i++)
	{
		if(postfix[i]==' ')
			continue;
			
		if(isdigit(postfix[i]))
		{
			int num=0;
			while(isdigit(postfix[i]))
			{
				num = num*10 + (int)(postfix[i] - '0');  // '2' - '0' = 50 - 48 = 2
				i++;
			}
			s.push(num);
		}
		else
		{
			int op1 = s.top();
			s.pop();
			int op2 = s.top();
			s.pop();
			switch (postfix[i])
			{
			case '+':
				s.push(op1 + op2);
				break;
			case '-':
				s.push(op1 - op2);
				break;
			case '*':
				s.push(op1 * op2);
				break;
			case '/':
				s.push(op1 / op2);
				break;
			case '^':
				s.push(op1 ^ op2);
				break;
			default:
				break;
			}
		}
	}
	return s.top();
}

int main()
{
	string postfix="5 4 * 2 +";
	cout<<solve(postfix); // 22
	return 0;
}
