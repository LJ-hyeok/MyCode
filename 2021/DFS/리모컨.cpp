#include<stdio.h>
int a,b;
int arr[] = {10,5,1,-10,-5,-1};
int ans = 40;

void dfs(int sum, int cnt)
{
	if(cnt>ans) return;
	
	if(sum == b){	
		if(cnt<ans) ans = cnt;
		return;
	}
	if(sum<b){
		for(int i=0;i<3;i++) dfs(sum+arr[i],cnt+1);
	}
	else{
		for(int i=3;i<=6;i++) dfs(sum+arr[i],cnt+1);
	}
	
}
int main(){
	scanf("%d %d",&a,&b);
	//
	dfs(a,0);
	//
	printf("%d",ans);
	
	return 0;
}
