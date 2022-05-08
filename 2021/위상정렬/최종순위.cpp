#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
int main(){
	int T,n,m;
	int score[505];
	bool arr[505][505];
	int indegree[505];
	cin >> T;
	while(T--){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
		memset(score,0,sizeof(score));
		memset(arr,0,sizeof(arr));
		memset(indegree,0,sizeof(indegree));
		
		
		cin >> n;
		for(int i=0;i<n;i++)	cin >> score[i];
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				arr[score[i]][score[j]] = true;
				indegree[score[j]]++;
			}
		}
		cin >> m;
		for(int i=0;i<m;i++){
			int a,b;
			cin >> a >> b;
			if(!arr[a][b]){
				arr[a][b] = true;
				arr[b][a] = false;
				indegree[a]--;
				indegree[b]++;
			}
			else{
				arr[a][b] = false;
				arr[b][a] = true;
				indegree[a]++;
				indegree[b]--;
			}
		}
		vector<int> v;
		queue<int> q;
		
		
		for(int i=1;i<=n;i++)
			if(indegree[i]==0)
				q.push(i);
	
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			v.push_back(cur);
			indegree[cur]--;//-1 == avoid
			for(int i=1;i<=n;i++){
				if(arr[cur][i]){
					indegree[i]--;
				if(indegree[i]==0)
					q.push(i);
				}
			}
		}
		if(v.size()==n){
			for(int i=0;i<n;i++)
				cout << v[i] << " ";
		}
		else
			cout << "IMPOSSIBLE";
		cout << "\n";
	}
		
	return 0;
}
