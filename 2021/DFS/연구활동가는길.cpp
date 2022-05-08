#include<stdio.h>
int n,m;
int arr[15][35];
bool chk[15][35];
int arr2[15];
int ans = 200;
void dfs(int sum,int idx)
{
	if(sum > 200)
		return;
		
	if(idx == n){
		if(ans > sum)
			ans = sum;
		return;
		
	}
	
	for(int i=1;i<=n;i++){
		if(chk[idx][i] == 1)
			dfs(sum+arr[idx][i],i);
	}
	
}

int main(){
	int a,b,c;
	int cnt = 0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		arr[a][b] = c;
//		arr[b][a] = c;
		chk[a][b] = true;
//		chk[b][a] = true;
	}
	//
	
//	for(int i=1;i<=n;i++) {
//		for(int j=1;j<=n;j++)
//			printf("%d\t",arr[i][j]);
//		printf("\n");
//	}

	//
	dfs(0,1);
	printf("%d",ans);
		
	return 0;
}
