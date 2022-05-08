#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	queue<int> q;
	string s;
	int N,X;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> s;
		if(s=="push"){
			cin >> X;
			q.push(X);
		}
		if(s=="pop"){
			if(q.empty())	
				cout << "-1\n";
			else{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		if(s=="size")
			cout << q.size() << "\n";
		if(s=="empty"){
			if(q.empty())	cout << "1\n";
			else	cout << "0\n";
		}
		if(s=="front"){
			if(q.empty())	cout << "-1\n";
			else	cout << q.front() << "\n";
		}
		if(s=="back"){
			if(q.empty())	cout << "-1\n";
			else	cout << q.back() << "\n";
		}
	}
}
