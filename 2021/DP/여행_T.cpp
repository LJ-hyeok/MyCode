#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int INF = 987654321;
int arr[301][301], dp[301][301];
int n,m,k;
int dfs(int idx, int cnt){
  if(idx == n) return 0;
  if(cnt == m) return -INF;
  if(dp[idx][cnt] != -1) return dp[idx][cnt];
  dp[idx][cnt] = -INF;
  for(int i=idx+1;i<=n;i++)
    if(arr[idx][i]) dp[idx][cnt] = max(dp[idx][cnt],arr[idx][i] + dfs(i,cnt+1));
  return dp[idx][cnt];
}
int main(){
  scanf("%d%d%d",&n,&m,&k);
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<k;i++){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    arr[a][b] = max(arr[a][b],c);
  }
  int ans = dfs(1,1);
  printf("%d\n",ans>0?ans:0);
  return 0;
}
