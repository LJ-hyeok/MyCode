#include<iostream>
#include<vector>
#include<queue>
using namespace std;

priority_queue<pair<int,int>> pq;
vector<pair<int,int>> v[1001];
priority_queue<int> Kdist[1001];
int n,m,k;

void dijkstra(){
	pq.push({0,1});

	while(!pq.empty()){
		pair<int,int> cur = pq.top();
		pq.pop();
		for(int i=0;i<v[cur.second].size();i++){
			int next = v[cur.second][i].first;
			int cost = v[cur.second][i].second - cur.first;
			if(Kdist[next].size()<k){			
				Kdist[next].push(cost);
				pq.push({-cost,next});
			}
			else if(Kdist[next].top() > cost){
				Kdist[next].pop();
				Kdist[next].push(cost);
				pq.push({-cost,next});
			}
			
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m >> k;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		v[a].push_back({b,c});
	}

	dijkstra();

	for(int i=1;i<=n;i++){
		if(Kdist[i].size() < k)
			cout << "-1\n";
		else
			cout << Kdist[i].top() << "\n";
	}

}
