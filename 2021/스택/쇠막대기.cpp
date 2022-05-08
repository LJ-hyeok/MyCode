#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<int> s;
string in;
int main(){
	cin >> in;
	bool chk = false;
	int ans = 0;
	for(int i=0;i<in.length();i++){
		if(in[i]=='('){//1
			s.push(1);
			chk = true;
		}
		if(in[i]==')'){//0
			if(chk){
				s.pop();
				ans+=s.size();
				chk = false;
			}
			else{
				s.pop();
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
