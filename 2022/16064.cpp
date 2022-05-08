#include<iostream>
#include<vector>
#define INF -987654321
using namespace std;

struct pt{
	int f,t,c;
};
vector<pt> v;
int dist[1001];
int n,m;

int Bellman(int s){
	for(int i=1;i<=n;i++)	dist[i] = INF;
	dist[s] = 0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<v.size();j++){
			int from = v[j].f;
			int to = v[j].t;
			int cost = v[j].c;
			if(dist[from] == INF)	continue;
			if(dist[to] < dist[from] + cost)
				dist[to] = dist[from] + cost;
		}
	}
	int res = 0;
	for(int i=1;i<=n;i++){
		if(dist[i]==INF)	continue;
		res = dist[i]>res?dist[i]:res;
	}
	return res;
}

int main(){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		v.push_back((pt){a,b,c});
	}
	
	int ans = 0;
	for(int i=1;i<=n;i++){
		int res = Bellman(i);
		ans = res>ans?res:ans;
	}
	
	cout << ans;
}
