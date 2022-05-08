#include<cstdio>
using namespace std;
int n,k;
int arr[101],dp[101];
int main(){
  scanf("%d%d",&n,&k);
  for(int i=0;i<k;i++) scanf("%d",arr+i);
  int res = 0;
  for(int i=0;i<k;i++){
    bool flag = false;
    for(int j=0;j<n;j++){
      if(dp[j] == arr[i]){
        flag = true;
        break;
      }
    }
    if(flag) continue;
    for(int j=0;j<n;j++){
      if(!dp[j]){
        dp[j] = arr[i];
        flag = true;
        break;
      }
    }
    if(flag) continue;
    int idx, idx2 = -1;
    for(int j=0;j<n;j++){
      int lastidx = 0;
      for(int l=i+1;l<k;l++){
        if(dp[j] == arr[l]) break;
        lastidx++;
      }
      if(lastidx>idx2){
        idx = j;
        idx2 = lastidx;
      }
    }
    res++;
    dp[idx] = arr[i];
    printf("\n");
    for(int l=0;l<k;l++)
    	printf("%d ",arr[l]);
  }
  printf("%d\n",res);
}
