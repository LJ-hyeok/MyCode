#include<iostream>
#include<queue>
#include<vector>
#define INF -100000000007
using namespace std;

struct pt{
	long long f,t,c;
};

queue<pt> q;
vector<pt> v;

vector<int> bv[101];
int tmp[101];

int N,s,e,M;
int money[101];
long long dist[101];

bool bfs(int x){
	if(x==e)	return true;
	fill(tmp,tmp+N,0);
	queue<int> bq;
	bq.push(x);
	tmp[x] = 1;
	while(!bq.empty()){
		int cur = bq.front();
		bq.pop();
		for(int i=0;i<bv[cur].size();i++){
			int next = bv[cur][i];
	 		if(tmp[next] == 0){
	 			if(next == e)	return true;
	 			bq.push(next);
	 			tmp[next] = 1;
	 		}
		}
	}
	return false;
}

void Bellman(){
	for(int i=0;i<N;i++)	dist[i] = INF;
	dist[s] = money[s];
	for(int i=0;i<N-1;i++){
		for(int j=0;j<v.size();j++){
			int from = v[j].f;
			int to = v[j].t;
			int cost = v[j].c;
			if(dist[from] == INF)	continue;
			if(dist[to] < dist[from] + cost)
				dist[to] = dist[from] + cost;
		}
	}
	
	for(int i=0;i<v.size();i++){
		int from = v[i].f;
		int to = v[i].t;
		int cost = v[i].c;
		if(dist[from] == INF)	continue;
		if(dist[to] < dist[from] + cost){
			if(bfs(from)){
				cout << "Gee";
				return;
			}
		}
	}
	
	dist[e]==INF?cout << "gg" : cout << dist[e];
	return;
}

int main(){
	//init
	cin >> N >> s >> e >> M;
	for(int i=0;i<M;i++){
		int a, b, c;
		cin >> a >> b >> c;
		q.push((pt){a,b,c});
		bv[a].push_back(b);
	}
	for(int i=0;i<N;i++)	cin >> money[i];
	while(!q.empty()){
		pt cur = q.front();
		q.pop();
		v.push_back((pt){cur.f, cur.t, money[cur.t]-cur.c});
	}

	//BellmanFord
	Bellman();
}
