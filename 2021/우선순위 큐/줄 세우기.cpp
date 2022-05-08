#include<iostream>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int> pq;
int indegree[32001];	
vector<int> arr[32001];

void dfs(int a){
	while(!arr[a].empty()&&arr[a].back()!=-1){
		dfs(arr[a].back());
		if(!arr[a].empty() && arr[a].back()!=-1 );
			cout << arr[a].back() << " ";
		arr[a].pop_back();
	}
	if(arr[a].empty())
		arr[a].push_back(-1);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int a, b;
		cin >> a >> b;
		arr[b].push_back(a);
		indegree[b]++;
	}
	for(int i=1;i<=N;i++)
		if(indegree[i]!=0) pq.push(i);

	while(!pq.empty()){
		if(arr[pq.top()].back()!=-1){
			dfs(pq.top());
			cout << pq.top() << " ";
		}
		pq.pop();
	}

	for(int i=1;i<=N;i++)
		if(arr[i].empty())
			cout << i << " ";
			
	return 0;
}
