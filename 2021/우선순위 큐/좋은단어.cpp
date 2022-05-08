#include<iostream>
#include<stack>
using namespace std;

int fn(string &s){
	stack<char> mystack;
	for(int i=0;i<s.length();i++){
		if(mystack.empty() || mystack.top()!=s[i])
			mystack.push(s[i]);
		else
			mystack.pop();
	}
	
	return mystack.empty();
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
	int ans = 0;
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		ans+=fn(s);
	}
	cout << ans; 
	return 0;
} 
