#include<iostream>//1 브루트포스 2 위상정렬  
#include<vector>
#include<queue>
using namespace std;
int com[13];
int dp[13];
vector<int> v[10];
priority_queue<int, vector<int>, greater<int> > q;
int main(){
	int k;
	cin >> k;
	for(int i=9-k;i<9;i++){
		char a;
		cin >> a;
		if(a=='<')
			com[i] = 1;
		if(a=='>')
			com[i] = 0;
	}
	
	for(int i=9-k;i<9;i++){
		if(com[i] == 1){
			v[i].push_back(i+1);
			dp[i+1]++;
		}
		if(com[i]==0){
			v[i+1].push_back(i);
			dp[i]++;
		}
	}
	
	for(int i=9-k;i<=9;i++)
		if(dp[i]==0)
			q.push(i);
	while(!q.empty()){
		int cur = q.top();
		q.pop();
		cout << cur;
		for(int i=0;i<v[cur].size();i++){
			if(--dp[v[cur][i]] == 0)
				q.push(v[cur][i]);
		}
	}

	//print vector 
//	for(int i=0;i<k+1;i++){
//		for(int j=0;j<v[i].size();j++)
//			cout << v[i][j] << " ";
//		cout << "\n";
//	}
	return 0;
}
//9
//< < < > < < > < >
