#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int MAX = 32e3+1;
int n,m;
int indegree[MAX];
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
  vector<int> arr[MAX];
//  priority_queue<int, vector<int>, greater<int> > pq;
	queue<int> pq;
  cin >> n >> m;
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    arr[a].push_back(b);
    indegree[b]++;
  }
  for(int i=1;i<=n;i++)
    if(!indegree[i]) pq.push(i);
  while(!pq.empty()){
    int cur = pq.front(); pq.pop();
    cout << cur << " ";
    for(int i=0;i<arr[cur].size();i++){
      if(--indegree[arr[cur][i]] == 0)
        pq.push(arr[cur][i]);
    }
  }
  return 0;
}
