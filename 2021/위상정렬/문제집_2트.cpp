#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int indegree[32001];
vector<int> v[32001]; 
priority_queue<int, vector<int>, greater<int> > pq;
int main(){
	int N,M;
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}
	for(int i=1;i<=N;i++)
		if(indegree[i] == 0)
			pq.push(i);
	while(!pq.empty()){
		int cur = pq.top();
		pq.pop();
		cout << cur << " ";
		for(int i=0;i<v[cur].size();i++){
			if(--indegree[v[cur][i]] == 0)
				pq.push(v[cur][i]);
		}
	}
	return 0;
}
