#include<stdio.h>
#define MAX (1LL<<63)-1
typedef long long ll;
ll arr[10005];
int k;
ll n;

ll BS(){
	ll start = 0;
	ll end=MAX;
	while(start<=end){
		ll mid = (start+end)/2;
		ll cnt = 0;
		for(int i=0;i<k;i++)
			cnt+=arr[i]/mid;
		if(cnt<n)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return end;
}

int main(){
	scanf("%d%lld",&k,&n);
	for(int i=0;i<k;i++)
		scanf("%lld",&arr[i]);
	printf("%lld",BS());

	return 0;
}

//https://www.acmicpc.net/problem/2512
