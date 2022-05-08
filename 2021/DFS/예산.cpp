#include<stdio.h>
int N,M;
int arr[10005];

int maxi(int a,int b){
	return a>b?a:b;
}

void dfs(int idx,int max)
{
	if(idx == N)
		idx = 0;
	if(arr[idx] == max)
		arr[idx] -= 1;
			
	int sum = 0;
	for(int i=0;i<N;i++)
		sum += arr[i];
		

	dfs(idx+1,max);
			
}
int main()
{	
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&arr[i]);
	scanf("%d",&M);
	
	//
	
	int max=0;
	int sum;
	for(int i=0;i<N;i++){
		max = maxi(max,arr[i]);
		sum+=arr[i];
	}
	
	//
	
	if(sum > M)
		dfs(0,max);	
		
	//
	
	max = 0;
	for(int i=0;i<N;i++){
		printf("%d ",arr[i]);
		max = maxi(max,arr[i]);
	}
	printf("\n%d",max);
	
	return 0;
}
