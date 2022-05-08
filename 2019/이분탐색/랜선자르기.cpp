#include<stdio.h>
typedef long long ll;
ll arr[10005];
int k;
ll n;
long long BS(void)
{
	
	ll cnt;
	ll min = 0;
	ll max = 10000000000;
	ll mid;
	while(min<=max)
	{
		mid = (min+max)/2;
		cnt = 0;
		
		for(int i=0;i<k;i++)
			cnt += arr[i]/mid;
//		printf("%d\t%d\t%d\t%lld\n",min,mid,max,cnt);
	
		
		if(cnt<n)
			max = mid-1;
		else
			min = mid+1;
		
		
		
	}
	return max;

}
int main()
{
	scanf("%d %d",&k,&n);
	for(int i=0;i<k;i++)
		scanf("%d",&arr[i]);
	printf("%lld",BS());
	return 0;
}

//https://www.acmicpc.net/problem/1654
