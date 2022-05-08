#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
queue<int> q;
stack<int> s;
vector<int> v[501];
int dp[501];
int ans[501];
int main(){
	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	int n;
	cin >> n;
	
	for(int i=1;i<=n;i++){
		cin >> ans[i];
		while(true){
			int a;
			cin >> a;
			if(a==-1)	break;
			v[i].push_back(a);
			dp[a]++;
		}
	}
	
	for(int i=1;i<=n;i++)
		if(dp[i]==0)
			q.push(i);
			
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		s.push(cur);
		for(int i=0;i<v[cur].size();i++)
			if(--dp[v[cur][i]]==0)
				q.push(v[cur][i]);
	}
	
	while(!s.empty()){
		int cur = s.top();
		s.pop();
		int tmp = ans[cur];
		for(int i=0;i<v[cur].size();i++)
			ans[cur] = max(ans[cur],tmp+ans[v[cur][i]]);
	}
	
	for(int i=1;i<=n;i++)
		cout << ans[i] << "\n";
	
	return 0;
}
