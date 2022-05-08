#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;

vector<pair<int,int>> v[201];
int dist[201];
int chk[201];
int n,m;

void dijkstra(int s){
	priority_queue<pair<int,int>> pq;
	for(int i=1;i<=n;i++){
		dist[i] = INF;
		chk[i] = 0;
	}
	for(int i=0;i<v[s].size();i++)	chk[v[s][i].first] = v[s][i].first;
	dist[s] = 0;
	pq.push({0,s});
	
	while(!pq.empty()){
		int cur = pq.top().second;
		pq.pop();
		for(int i=0;i<v[cur].size();i++){
			int next = v[cur][i].first;
			int cost = v[cur][i].second;
			if(dist[next] > dist[cur] + cost){
				dist[next] = dist[cur] + cost;
				if(cur!=s)	chk[next] = chk[cur];
				pq.push({-dist[next],next});
			}
		}
	}
	return;
}

int main(){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	
	for(int i=1;i<=n;i++){
		dijkstra(i);
		for(int j=1;j<=n;j++){
			if(i==j)	cout << "- ";
			else	cout << chk[j] << " ";
		}
		cout << "\n";
	}
	
}
