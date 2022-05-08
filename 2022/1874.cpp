#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(){
	queue<int> ans;
	stack<int> tmp;
	int n;
	int arr[100001];
	cin >> n;
	for(int i=0;i<n;i++)	cin >> arr[i];
	
	int cursor = 0;
	for(int i=1;i<=n;i++){
		tmp.push(i);
		ans.push(1);
		while(!tmp.empty() && tmp.top()==arr[cursor]){
			tmp.pop();
			ans.push(0);
			cursor++;
		}
	}
	if(tmp.empty()){
		while(!ans.empty()){
			if(ans.front())	cout << "+\n";
			else 			cout << "-\n";
			ans.pop();
		}
	}
	else
		cout << "NO";
}
