#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int t[1003];
vector<int> v[1003];
int dp[1003];
int N,K,D,W;
int ans[1003];
void dfs(int idx){
    dp[idx]--;
    for(int i=0;i<v[idx].size();i++){
      ans[v[idx][i]] = max(ans[v[idx][i]], ans[idx] + t[v[idx][i]]);
      if(!(--dp[v[idx][i]])) dfs(v[idx][i]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        memset(v,0,sizeof(v));
        memset(ans,0,sizeof(ans));
        memset(dp,0,sizeof(dp));
        cin >> N >> K;
        for(int i=1;i<=N;i++)
            cin >> t[i];
        for(int i=0;i<K;i++){
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            dp[b]++;
        }
        cin >> W;
        for(int i=1;i<=N;i++){
          if(!dp[i]){
            ans[i] = t[i];
            dfs(i);
          }
        }
        cout << ans[W] << "\n";
    }
    return 0;
}
