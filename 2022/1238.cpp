#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

vector<pair<int,int>> v[1001];
priority_queue<pair<int,int>> pq;
int dist[1001];
int ans[1001];
int N,M,X;

void dijkstra(int s, bool flag){
	fill(dist+1,dist+1+N,INF);
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
				pq.push({-dist[next], next});
			}
		}
	}
	
	if(!flag)
		ans[s] = dist[X];
	
	if(flag)
		for(int i=1;i<=N;i++)
			ans[i] += dist[i];
	return;
}

int main(){
	//init
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M >> X;
	for(int i=0;i<M;i++){
		int a,b,c;
		cin >> a >> b >> c;
		v[a].push_back({b,c});
	}
	
	//dijkstra
	for(int i=1;i<=N;i++)
		dijkstra(i,false);
	dijkstra(X,true);
	
	//max value in ans
	int res = 0;
	for(int i=1;i<=N;i++)
		res = max(res,ans[i]);
		
	//output	
	cout << res;
	return 0;
}
