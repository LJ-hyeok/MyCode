#include<stdio.h>
int N,K;
long long arr[10005];
int BS()
{
	long long max = 10000000000;
	long long min = 0;
	long long mid = max/2;
	long long cnt;
	long long ans = 0;
	printf("%d\t%d\t%d\t%d\n",min,mid,max,cnt);
	while(min <= max){
		cnt = 0;
		for(int i=0;i<N;i++){
			cnt += arr[i]/mid;
		}
		if(cnt < K){
			max = mid-1;
		}
		else{
			min = mid+1;
		}
		mid = (max+min)/2;
		if(cnt == K && mid > ans)
			ans = mid;
		printf("%d\t%d\t%d\t%d\n",min,mid,max,ans);
	}
	return mid;
	
}
int main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
		scanf("%lld",&arr[i]);
	printf("%lld",BS());
	return 0;
}
