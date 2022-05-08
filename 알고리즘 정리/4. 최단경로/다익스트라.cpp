//BOJ_1916
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

priority_queue<pair<int,int>> pq;
vector<pair<int,int>> v[100001];
const int INF = 987654321;
int dist[1001];
int arr[1001][1001];

int dijkstra(int s,int e){
	dist[s] = 0;
	pq.push({0,s});
	while(!pq.empty()){
		int cur = pq.top().second;
		pq.pop();
		for(int i=0;i<v[cur].size();i++){
			int next =  v[cur][i].first;
			int cost =  v[cur][i].second;
			if(dist[next] > dist[cur] + cost){
				dist[next] = dist[cur] + cost;
				pq.push({-dist[next],next});
			}
		}
	}
	return dist[e];
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N,M;
	cin >> N >> M ;
	for(int i=1;i<=N;i++)	dist[i] = INF;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)	
			arr[i][j] = INF;
	for(int i=0;i<M;i++){
		int a,b,c;
		cin >> a >> b >> c;
		arr[a][b] = min(arr[a][b],c);
	}
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			if(arr[i][j]!=INF)
				v[i].push_back({j,arr[i][j]});
	int s,e;
	cin >> s >> e;
	cout << dijkstra(s,e);
}
