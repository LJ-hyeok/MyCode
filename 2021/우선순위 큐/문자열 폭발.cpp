#include<iostream>
#include<stack>
using namespace std;

stack<char> st1,st2;
string s,b;

void fn(){
	while(!st2.empty())	st2.pop();
	for(int i=b.length()-1;i>=0;i--){
		if(st1.empty() || b[i]!=st1.top())
		{
			while(!st2.empty())	{st1.push(st2.top());st2.pop();}
			return;
		}
		if(b[i]==st1.top())	{st2.push(st1.top());st1.pop();}
	}
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
	cin >>  s >> b;
	for(int i=0;i<s.length();i++)
	{
		st1.push(s[i]);
		if(st1.top()==b[b.length()-1])
			fn();
	}
	
	if(st1.empty())	cout << "FRULA";
	else
	{
		stack<char> ans;
		while(!st1.empty())	{ans.push(st1.top());st1.pop();}
		while(!ans.empty())	{cout << ans.top();ans.pop();}
	}	
	return 0;
}
