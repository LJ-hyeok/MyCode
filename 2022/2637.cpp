#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<pair<int,int>> v[101];
queue<int> q;
int indegree[101];
int arr[101][101];
int N,M;

void fn(int f, int t, int w){
	for(int i=1;i<=N;i++)
		if(arr[f][i])
			arr[t][i] += arr[f][i]*w;
}

int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int X,Y,K;
		cin >> X >> Y >> K;
		v[Y].push_back({X,K});
		indegree[X]++;
	}
	
	for(int i=1;i<=N;i++){
		if(indegree[i] == 0){
			q.push(i);
			arr[i][i] = 1;
		}
	}
			
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i=0;i<v[cur].size();i++){
			pair<int,int> next = v[cur][i];
			fn(cur, next.first, next.second);
			if(--indegree[next.first]==0){
				q.push(next.first);
			}
		}
	}
	for(int i=1;i<=N;i++)
		if(arr[N][i])
			cout << i <<  " " << arr[N][i] << "\n";

}
