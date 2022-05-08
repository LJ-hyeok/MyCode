/*
DP
���簡 �󸮾�����̸� �����Ѱ��� �󸮾���Ͱ� �ƴϴ�
���簡 �󸮾���Ͱ� �ƴϸ� ������ ���� �󸮾�����̰ų� �󸮾���Ͱ� �ƴϴ�.

dp[i][j]  ���� i��° ��尡 j==0 �϶��� �󸮾���Ͱ� �ƴҶ�, j==1 �϶��� �󸮾�����϶� �� ����.
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
vector<int> v[1000002];
int dp[1000002][2];
int dfs(int pre, int cur, bool chk){
  if(dp[cur][chk]!=-1) return dp[cur][chk];
  dp[cur][chk] = 0;
  for(int i=0;i<v[cur].size();i++){ //���� ��ġ���� ����� ��� ���� Ȯ��
    int nxt = v[cur][i]; //���� ���
    if(nxt == pre) continue; //���� ��ġ�� ���� ��ġ�� �����ϸ� ��ŵ
    if(chk) dp[cur][chk] += dfs(cur,nxt,0);
    else if(!chk) dp[cur][chk] += max(dfs(cur,nxt,1)+1,dfs(cur,nxt,0));
  }
  return dp[cur][chk];
}
int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n-1;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    //����� �׷���
    v[a].push_back(b);
    v[b].push_back(a);
  }
  memset(dp,-1,sizeof(dp)); //dp�� ���� -1 �� ���� (���� �湮���� ���� ���� -1 �� �Ѵ�)
  printf("%d",n - max(dfs(-1,1,0),dfs(-1,1,1)+1));
}
