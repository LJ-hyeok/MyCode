#include<iostream>
#include<stack>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	while(true){
		stack<int> tmp;
		while(!tmp.empty())	tmp.pop();
		string input;
		getline(cin,input);
		
		if(input.length()==1 && input[0]=='.')	break;;
		
		bool flag  = true;
		for(int i=0;i<input.length();i++){
			if(input[i]=='(')	tmp.push(1);
			if(input[i]=='[')	tmp.push(2);
			
			if(input[i]==')'){
				if(tmp.empty())	flag = false;
				else{
					if(tmp.top()!=1)	flag = false;
					tmp.pop();
				}
			}
			if(input[i]==']'){
				if(tmp.empty())	flag = false;
				else{
					if(tmp.top()!=2)	flag = false;
					tmp.pop();
				}
			}
		}
		
		if(!tmp.empty() || flag==false)	cout << "no\n";
		else	cout << "yes\n";
	}
}
