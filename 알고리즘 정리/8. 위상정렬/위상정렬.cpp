//BOJ_2252
#include<iostream>
#include<vector>
#include<queue> 
using namespace std;

vector<int> v[32001];
int indegree[32001];
queue<int> q;

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N,M;
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		++indegree[b];
	}
	
	for(int i=1;i<=N;i++)
		if(!indegree[i])
			q.push(i);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for(int i=0;i<v[cur].size();i++){
			if(--indegree[v[cur][i]]==0)
				q.push(v[cur][i]);
		}
	}
}
