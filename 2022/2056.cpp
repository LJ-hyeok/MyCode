#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> v[10001];
int indegree[10001];
int t[10001];
int d[10001];
queue<int> q;

int main(){
	int N;
	cin >> N;
	for(int i=1;i<=N;i++){
		int time,cnt;
		cin >> time >> cnt;
		t[i] = time;
		for(int j=0;j<cnt;j++){
			int b;
			cin >> b;
			v[b].push_back(i);
			indegree[i]++;
		}
	}
	
	
	for(int i=1;i<=N;i++){
		if(indegree[i]==0){
			q.push(i);
			d[i] = t[i];
		}
	}

	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i=0;i<v[cur].size();i++){
			d[v[cur][i]] = max(d[v[cur][i]], d[cur] + t[v[cur][i]]);
			if(--indegree[v[cur][i]]==0){
				q.push(v[cur][i]);
			}
		}
	}
	
	int ans = 0;
	for(int i=1;i<=N;i++)		ans = d[i]>ans?d[i]:ans;
	cout << ans;
}
