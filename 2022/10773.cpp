#include<iostream>
#include<stack>
using namespace std;
int main(){
	stack<int> s;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int tmp;
		cin >> tmp;
		if(tmp==0)	s.pop();
		else s.push(tmp);
	}
	
	int ans = 0;
	while(!s.empty()){
		ans+=s.top();
		s.pop();
	}
	cout << ans;
}
