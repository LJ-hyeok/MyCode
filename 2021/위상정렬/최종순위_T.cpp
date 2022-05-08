#include <bits/stdc++.h>
using namespace std;
// 원래의 완벽한 순서를 주고, 순위가 바뀐 모든 팀의 목록을 주므로 ? 인 경우는 없다.
int T, N, M;
int score[555];
bool adj[555][555];
int indegree[555];
int main(){ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
cin >> T;
while(T--){
    // initialization 
    memset(indegree,0,sizeof(indegree));
    memset(adj,false,sizeof(adj));
    
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> score[i];
    for (int i = 0; i < N; ++i){
        for (int j = i+1; j < N; ++j){
            adj[score[i]][score[j]] = true;
            indegree[score[j]]++;
        }
    }
        
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        // 원래 a가 b 앞이었던 경우
        if(adj[a][b]){
            adj[a][b] = false;
            adj[b][a] = true;
            // b가 a 앞이 된다 생각
            indegree[b]--;
            indegree[a]++;
        }
        // 원래 b가 a 앞이었던 경우
        else {
            adj[b][a] = false;
            adj[a][b] = true;
            indegree[a]--;
            indegree[b]++;
        }
    }
    // Topological Sort
    queue<int> Q;
    for (int i = 1; i <= N; ++i)
        if(indegree[i]==0) Q.push(i);
    vector<int> ans;
    for (int k = 0; k < N; k++) {
        if(Q.empty()) break;
        
        int now = Q.front();
        Q.pop();
        ans.push_back(now);
        // make indegree<0 avoid repetation
        indegree[now]--;
        for (int i = 1; i <= N; i++) {
            if (adj[now][i]) indegree[i]--;
            if (indegree[i] == 0) Q.push(i);
        }
    }
    // case of finding all ranking
    if(ans.size()==N){
        for (int i = 0; i < N; i++) 
            cout << ans[i] << ' ';
        cout << '\n';
    }
    // or not
    else
        cout << "IMPOSSIBLE" << '\n';
}
return 0;
}
