#include<stdio.h>
int arr[15];
bool vis[15];
int k=1;
void dfs(int idx)
{
	if(idx > k)
		return;
	if(cnt >= 6)	
	{
		for(int i=0;i<k;i++)
			if(vis[i]==1)
				printf("%d ",arr[i]);
		printf("\n");
		return;
	}
	
	vis[idx] = 1;
	dfs(idx + 1);
	vis[idx] = 0;
	dfs(idx+1);
	
}
//1 1 1 1 1 0 1 1
int main(){
	while(k!=0)
	{
		scanf("%d",&k);
		for(int i=0;i<k;i++)
			scanf("%d",&arr[i]);
		for(int i=0;i<15;i++)
			vis[i] = 0;
		dfs(0);
		printf("\n");
	}
	return 0;
}
