#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct pt{
	int t,w,chk;
};

queue<int> q;
vector<pt> v[10001];
vector<pt> Bv[10001];
int indegree[10001];
int d[10001];


int BackTracking(int s, int e){
	int ret = 0;
	queue<int> Bq;
	Bq.push(e);
	while(!Bq.empty()){
		int cur = Bq.front();
		Bq.pop();
		for(int i=0;i<Bv[cur].size();i++){
			if(d[Bv[cur][i].t] == d[cur] - Bv[cur][i].w && Bv[cur][i].chk){
				Bq.push(Bv[cur][i].t);
				Bv[cur][i].chk = 0;
				ret++;
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n,m,s,e;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		v[a].push_back((pt){b,c});
		Bv[b].push_back((pt){a,c,1});
		indegree[b]++;
	}
	cin >> s >> e;
	
	for(int i=1;i<=n;i++)
		if(indegree[i]==0)
			q.push(i);

	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i=0;i<v[cur].size();i++){
			d[v[cur][i].t] = max(d[v[cur][i].t], d[cur] +  v[cur][i].w);
			if(--indegree[v[cur][i].t]==0)
				q.push(v[cur][i].t);
		}
	}
	
	int ans = BackTracking(s,e);
	cout << d[e] << " " << ans;
}


