#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int mx = 1000000;

priority_queue<pair<int,int>> pq;
vector<int> v[mx + 1];
int p[mx + 1];
int r[mx + 1];

int find(int u){
	if(p[u] == u)	return u;
	return p[u] = find(p[u]);
}

void Union(int u, int v){
	u = find(u);
	v = find(v);
	if(u==v)	return;
	if(r[u]>r[v])	swap(u,v);
	p[u] = v;
	if(r[u]==r[v])	++r[v];
}

int main(){
	int N;
	cin >> N;
	for(int i=1;i<=N;i++)	p[i] = i;
	for(int i=0;i<N-1;i++){
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i=1;i<=N;i++)	pq.push({v[i].size(),i});
	
	int cnt = 0;
	while(!pq.empty()){
		int idx = pq.top().second;
		pq.pop();
		bool flag = false;
		for(int i=0;i<v[idx].size();i++)
			if(find(v[idx][i]) != find(idx))
				flag  = true;
		if(flag){
			cout << idx << ' ' ;
			for(int i=0;i<v[idx].size();i++)	Union(idx,v[idx][i]);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
