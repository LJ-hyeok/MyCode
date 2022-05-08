#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct pt{
	int n;
	bool c;
};

vector<int> edge[20003];
int chk[20003];
int vis[20003];

void init(){
	int mx = 20000;
	for(int i=1;i<=mx;i++){
		edge[i].clear();
		chk[i] = vis[i] = 0;
	}
}

void paint(int x,bool f){
	if(chk[x]!=0)	return;
	chk[x] = f+1;
	for(int i=0;i<edge[x].size();i++)
		paint(edge[x][i],!f);
}

bool verify(int x,bool f){
	queue<pt> q;
	q.push((pt){x,f});
	vis[x] = 1;
	
	while(!q.empty()){
		int cur = q.front().n;
		bool color = q.front().c;
		q.pop();
		for(int i=0;i<edge[cur].size();i++){
			int next = edge[cur][i];
			if(chk[next] != !color+1)
				return false;
			if(vis[next]==0){
				vis[next]=1;
				q.push((pt){next,!color});
			}
		}
	}
	return true;
}

int main(){
	int K;
	cin >> K;
	while(K--){
		init();
		int V,E,u,v;
		cin >> V >> E;
		for(int i=0;i<E;i++){
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		
		for(int i=1;i<=V;i++)
			if(chk[i]==0)
				paint(i,1);
		
		bool ans=true;
		for(int i=1;i<=V;i++){
			if(!ans)
				continue;
			if(vis[i]==0)
				ans = verify(i,chk[i]-1);
		}
		ans ? cout<<"YES\n" : cout << "NO\n";
	}
}
