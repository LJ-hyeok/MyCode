#include<stdio.h> 
int arr[305];
int dp[305];
int n;
inline int max(int a, int b){return a>b?a:b;}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
		
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[0]+arr[2],arr[1]+arr[2]);
	int cnt = 2;
	
	for(int i=3;i<n;i++){
		dp[i] = max(arr[i]+dp[i-2],arr[i]+arr[i-1]+dp[i-3]);
	}
	
	printf("%d",dp[n-1]);
	return 0;
}
