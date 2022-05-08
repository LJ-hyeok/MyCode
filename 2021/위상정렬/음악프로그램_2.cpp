#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
	int N,M;
	int indegree[1003];
	vector<int> v[1003];
	queue<int> q;
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int n,a,b;
		cin >> n >> a;
		for(int i=0;i<n-1;i++){
			cin >> b;
			v[a].push_back(b);
			indegree[b]++;
			a=b;
		}
	}
	
	for(int i=1;i<=N;i++)
		if(indegree[i]==0)
			q.push(i);
	
	vector<int> ans;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		ans.push_back(cur);
		for(int i=0;i<v[cur].size();i++){
			if(--indegree[v[cur][i]]==0)
				q.push(v[cur][i]);
		}
	}
	if(ans.size()==N)
		for(int i=0;i<N;i++)
			cout << ans[i] << "\n";
	else
		cout << '0';
	return 0;
}
