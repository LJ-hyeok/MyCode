
#include<stdio.h>
#define MAX 105
#define INF 987654321
int G[MAX][MAX];
int cnt[MAX];
int n,m;
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) if(i!=j) G[i][j]=INF;
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    G[a][b]=1;
  }
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      if(k==i) continue;
      for(int j=1;j<=n;j++)
        if(k==j || i==j) continue;
        else G[i][j] = (G[i][j]>G[i][k]+G[k][j]) ? G[i][k]+G[k][j]:G[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
      if(G[i][j]>=0 && G[i][j]<INF){
	  	cnt[i]++,cnt[j]++;
	  }
  }
  for(int i=1;i<=n;i++)
    printf("%d\n",n-(cnt[i]-1));
  return 0;
}
