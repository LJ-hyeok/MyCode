#include<iostream>
#include<string>
#include<stack>
using namespace std; 
stack<int> s;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string in;
	int a;
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> in;
		if(in == "push"){
			cin >> a;
			s.push(a);
		}
		if(in == "pop"){
			if(s.empty())
				cout<<"-1\n";
			else{
				cout<<s.top()<<"\n";
				s.pop();
			}
		}	
		if(in == "size") cout << s.size()<<"\n";
		if(in == "empty"){
			if(s.empty())
				cout <<"1\n";
			else
				cout<<"0\n";
		}
		if(in == "top"){
			if(s.empty())
				cout<<"-1\n";
			else
				cout<<s.top()<<" \n";
		}
	}

	return 0;
}
