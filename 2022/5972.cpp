#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;

vector<pair<int,int>> v[50001];
int dist[50001];
int N,M;

int dijkstra(){
	priority_queue<pair<int,int>> pq;
	for(int i=1;i<=N;i++)	dist[i] = INF;
	dist[1] = 0;
	pq.push({0,1});
	while(!pq.empty()){
		int cur = pq.top().second;
		pq.pop();
		for(int i=0;i<v[cur].size();i++){
			int next = v[cur][i].first;
			int cost = v[cur][i].second;
			if(dist[next] > dist[cur] + cost){
				dist[next] = dist[cur] + cost;
				pq.push({-dist[next],next});
			}
		}
	}
	return dist[N];
}

int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int a,b,c;
		cin >> a >> b >> c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	
	cout << dijkstra();
}
