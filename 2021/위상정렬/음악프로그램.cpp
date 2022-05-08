#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N,M;
int cnt,a,b;
int chk = 0;
int indegree[1005];
vector<int> v[1005];
queue<int> q;
queue<int> ans;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	for(int i=0;i<M;i++){
		cin >> cnt;
		cin >> a;
		for(int j=1;j<cnt;j++){
			cin >> b;
			v[a].push_back(b);
			indegree[b]++;
			a = b;
		}
	}
	for(int i=1;i<=N;i++)
		if(!indegree[i])	q.push(i);
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(int i=0;i<v[cur].size();i++)
			if(--indegree[v[cur][i]]==0)
				q.push(v[cur][i]);
		ans.push(cur);
		chk++;
	}
	if(chk==N){
		while(!ans.empty()){
			int cur = ans.front(); ans.pop();
			cout << cur << "\n";
		}
	}
	else
		cout << "0";
	return 0;
}
