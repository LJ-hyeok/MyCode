#include<stdio.h>
#define MAX 1000005
typedef long long ll;
int n;
ll m;
ll tree[MAX];

bool check(int length){
	ll ans = 0;
	for(int i=0;i<n;i++){
		if(tree[i]>=length) ans += (tree[i]-length);
	}
	if(ans >= m) return true;
	else return false;
}
int main(){
	scanf("%d%lld",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%lld",&tree[i]);
	ll e;
	ll s;
	s = 0;
	e = 1e9;
	while(s<=e){
		ll mid = (s+e)/2;
		if(check(mid)) s = mid + 1;
		else e = mid - 1;
	}
	printf("%lld",e);
	return 0;
}
