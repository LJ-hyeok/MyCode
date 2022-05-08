#include<iostream>
#include<string>
using namespace std;
int main(){
	string S;
	getline(cin,S);
	int h=0,s=0;
	for(int i=0;i<S.length();i++){
		if(S[i]==':' && S[i+1]=='-'){
			if(S[i+2]==')')
				h++;
			if(S[i+2]=='(')
				s++; 
		}
	}
	if(h==0&&s==0)
		cout << "none";
	else if(h>s)
		cout << "happy";
	else if(h==s)
		cout << "unsure";
	else if(h<s)
		cout << "sad";
}
