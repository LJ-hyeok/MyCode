#include<stdio.h>
#include<vector>
#include<algorithm>
//#include<bits/stdc++.h>
using namespace std;
int const mxN = 200000;
int const mxS = 2000;
struct ball{
	int color,size;
	int num;
	int value;
};
ball arr[mxN+3];
int dp[mxS+3][2];
bool cmp(ball a,ball b){
	if(a.color == b.color)
		return a.size < b.size;
	return a.color < b.color;
}
bool cmp2(ball a,ball b){
	return a.num < b.num;
}
int main(){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		arr[i].color = a;
		arr[i].size = b;
		arr[i].num = i;
		
	}
	sort(arr+1,arr+N+1,cmp);
	
	for(int i=1;i<=N;i++){
		dp[arr[i].size][0] = arr[i].size;
		dp[0
	}
	for(int i=1;i<=mxS;i++)
		dp[i] += dp[i-1];

	int pre = 0, sum = 0;
	for(int i=1;i<=N;i++){
		if(arr[pre].color!=arr[i].color)
			sum = 0;
		else if(arr[pre].size == arr[i].size){
			arr[i].value = dp[arr[i].size] - sum;
			continue;
		}
		sum+=arr[i].size;
		arr[i].value = dp[arr[i].size] - sum;
		pre = i;
	}
	sort(arr+1,arr+N+1,cmp2);
	for(int i=1;i<=N;i++)
		printf("%d ",arr[i].value);
	
	
	return 0;
}
4
1 20
1 20
3 30
3 30

