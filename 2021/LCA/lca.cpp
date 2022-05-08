#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N,M;
vector<int> v[500003];
int p[50003];
int d[50003];
int lca(int u, int v){
	if(d[u]>d[v])	swap(u,v);
	while(d[u]!=d[v])	v=p[v];
	while(u!=v){
		u=p[u];
		v=p[v];
	}
	return u;
}
int main(){
	cin >> N;
	for(int i=0;i<N-1;i++){
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	
	queue<int> q;
	q.push(1);
	p[1] = 1;
	
	while(!q.empty()){ios_base::sync_with_stdio(false);cin.tie(NULL);
		int cur = q.front();
		q.pop();
		for(int i=0;i<v[cur].size();i++){
			if(!p[v[cur][i]]){
				p[v[cur][i]]=cur;
				q.push(v[cur][i]);
				d[v[cur][i]]=d[cur]+1;
			}
		}
	}
	
	cin >> M;
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		cout << lca(a,b) << '\n';
	}
	return 0;
}

