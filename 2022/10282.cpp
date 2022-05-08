#include<iostream>
#include<queue>
#include<vector>
#define INF 987654321
using namespace std;
priority_queue<pair<int,int>> pq;
vector<pair<int,int>> v[10001];
int n,d,c;
int dist[10001];

void dijkstra(int s){
	pq.push({0,s});
	dist[s] = 0;
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
	return;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		for(int i=0;i<=n;i++)	v[i].clear();
		cin >> n >> d >> c;
		for(int i=0;i<d;i++){
			int a,b,s;
			cin >> a >> b >> s;
			v[b].push_back({a,s});
		}
	
		fill(dist+1,dist+1+n,INF);
		dijkstra(c);

		int cnt = 0, mx = 0;
		for(int i=1;i<=n;i++){
			if(dist[i]!=INF){
				mx = max(mx, dist[i]);
				cnt++;
			}
		}
		cout << cnt << " " << mx << "\n";
	}
	return 0;
}
