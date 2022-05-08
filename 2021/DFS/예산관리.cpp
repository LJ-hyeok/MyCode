#include<stdio.h>
int B,n;
int arr[25];
int max = 0;
int maxi(int a,int b){
	return a>b?a:b;
}
void dfs(int idx,int sum)
{
	if(idx >= n)
	{
		if(sum <=  B)
			max = maxi(sum,max);
//		printf("%d\t%d\n",sum,max);
		return;
			
	}
	dfs(idx+1,sum+arr[idx]);
	dfs(idx+1,sum);
}

int main(){
	scanf("%d",&B);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	//
	dfs(0,0);
	//
	printf("%d",max);
	return 0;
}

//40
//6
//7 13 17 19 29 31
//
//39
