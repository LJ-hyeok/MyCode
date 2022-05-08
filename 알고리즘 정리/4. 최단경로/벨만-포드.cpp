//BOJ_11657
#include<iostream>
#include<vector>
using namespace std;

struct pt{int f,t,w;};
vector<pt> v;
const int INF = 987654321;
int N,M;
long long int dist[501];////////////////////////////long long  ¿Œ¡ˆ ∆«¥‹ ¿ﬂ«œº¿ §µ§≤  

bool Bellman_ford(){
	for(int i=1;i<=N;i++)	dist[i]=INF;
	dist[1] = 0;
	for(int i=0;i<N-1;i++){
		for(int j=0;j<v.size();j++){
			int from = v[j].f;//////////////////////////////i∑Œ ¬¯∞¢«œ¡ˆ∏∂º¿ §µ§≤ 
			int to = v[j].t;
			int cost = v[j].w;
			if(dist[from]==INF) continue;
			if(dist[to] > dist[from] + cost)
				dist[to] = dist[from] + cost;
		}
	}
	for(int i=0;i<v.size();i++){
		int from = v[i].f;
		int to = v[i].t;
		int cost = v[i].w;
		if(dist[from]==INF) continue;
		if(dist[to] > dist[from] + cost)
			return false;
	}
	return true;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M ;
	for(int i=0;i<M;i++){
		int a,b,c;
		cin >> a >> b >> c;
		v.push_back((pt){a,b,c});
	}
	if(Bellman_ford()){
		for(int i=2;i<=N;i++)
			if(dist[i]==INF)	cout << "-1\n";
			else cout << dist[i] << "\n";
	}
	else	cout << "-1\n";
}
