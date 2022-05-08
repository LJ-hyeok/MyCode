#include<iostream>
#include<stack>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		stack<int> Mystack;
		while(!Mystack.empty())	Mystack.pop();
		bool flag = true;
		
		for(int j=0;j<s.length();j++){
			if(s[j]=='('){
				Mystack.push(s[i]);
			}
			if(s[j]==')'){
				if(Mystack.empty())		flag = false;
				else					Mystack.pop();
			}
		}
		if(!Mystack.empty())	flag = false;
		flag?cout<<"YES\n":cout<<"NO\n";
	}
}
