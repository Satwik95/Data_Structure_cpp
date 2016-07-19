#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isPaired(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}

bool isbalanced(string exp)
{	
	stack<char> s;
	for(int i = 0;i<exp.length();i++)
	{
		if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
			s.push(exp[i]);
		else if(s.empty() || !isPaired(exp[i],s.top()))
			return false;
		else
			s.pop();
	}

	return true;
}


int main()
{
	string exp;
	cout<<"Enter an expression"<<endl;
	cin>>exp;

	if(isbalanced(exp))
		cout<<"Balanced!";
	else
		cout<<"Not Balanced!";

}