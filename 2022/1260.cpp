#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> v[1003];
int chk[1003];
int N,M,V;

void dfs(int x){
	if(chk[x]==1)	return;
	chk[x]=1;
	cout << x << " ";
	for(int i=0;i<v[x].size();i++)
		dfs(v[x][i]);
}

void bfs(int x){
	queue<int> q;
	chk[x]=1;
	q.push(x);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for(int i=0;i<v[cur].size();i++){
			if(chk[v[cur][i]]==0){
				chk[v[cur][i]]=1;
				q.push(v[cur][i]);
			}
		}
	}
}

void init(){
	for(int i=1;i<=N;i++)
		chk[i]=0;
	cout << "\n";
}

int main(){
	cin >> N >> M >> V;
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i=1;i<=N;i++)
		sort(v[i].begin(),v[i].end());
		
	dfs(V);
	init();
	bfs(V);
}
