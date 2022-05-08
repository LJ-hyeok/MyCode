#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
 
int N, M;
int A, B, C;
int from, to;
vector<pair<int, int>> graph[10001];
bool visit[10001];
int result;
 
bool bfs(int w){
    queue<int> q;
    visit[from] = true;
    q.push(from);
 
    while (!q.empty()){
        int cur = q.front();
        q.pop();
 
        if (cur == to) return true;
 
        for (int i=0; i<graph[cur].size(); i++){
            int next = graph[cur][i].first;
            if (!visit[next] && w <= graph[cur][i].second){
                q.push(next);
                visit[next] = true;
            }
        }
    }
 
    return false;
}
 
void binarySearch(){
    int left = 1;
    int right = 1000000000;
 
    while (left <= right){
        int mid = (left + right) / 2;
        memset(visit, false, sizeof(visit));
 
        if (bfs(mid)){
            result = max(result, mid);
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
}
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    cin >> N >> M;
 
    for (int i=0; i<M; i++){
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }
 
    cin >> from >> to;
    binarySearch();
 
    cout << result;
 
    return 0;
}
