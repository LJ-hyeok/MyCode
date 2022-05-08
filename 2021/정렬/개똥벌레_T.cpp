#include<stdio.h>
int arr[500001];
int main(){
  int n,h;
  scanf("%d%d",&n,&h);
  n/=2;
  for(int i=0;i<n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    --arr[a],++arr[h-b];
  }
  int mn = n, cnt = 1, curr = n;
  for(int i=1;i<h;i++){
    curr+=arr[i];
    if(curr==mn)
		++cnt;
    else if(curr<mn) 
		mn = curr, cnt = 1;
  }
  
  printf("%d %d",mn,cnt);
}
