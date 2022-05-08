#include<stdio.h>
int k;
int arr[14];
bool chk[200000 * 14]; 
int sum;
void dfs(int idx, int left, int right)
{
	if(idx == k){
		if(right-left > 0)chk[right-left] = true;
//		if(left-right > 0)chk[left-right] = true;
		return;
	}
	dfs(idx+1,left+arr[idx],right);
	dfs(idx+1,left,right+arr[idx]);
	dfs(idx+1,left,right);
}
int main()
{
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	dfs(0,0,0);
	int cnt = 0;
	for(int i=1;i<=sum;i++){
		if(!chk[i]) printf("%d ",i);//cnt++;
	}
	printf("\n%d",cnt);
	//
	
	return 0;
}
