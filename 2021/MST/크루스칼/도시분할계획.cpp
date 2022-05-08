#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int chk[100001];
struct node{
	int a,b,c;
};
bool cmp(node a,node b){
	return a.c<b.c;
}
int find(int x){
	if(x == chk[x])
		return x;
	return chk[x] = find(chk[x]);
}
vector<node> arr;
int main(){
	int ans = 0;
	int  N, M;
	int last;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
		chk[i] = i;
	for(int i=0;i<M;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		arr.push_back({a,b,c});
	}
	sort(arr.begin(),arr.end(),cmp);
	for(int i=0;i<M;i++){
		int pre = find(arr[i].a);
		int next = find(arr[i].b);
		if(pre == next)
			continue;
		chk[pre] = next;
		ans += arr[i].c;
		printf("\n%d %d",arr[i].a,arr[i].b);
		last = arr[i].c;
	}
	printf("%d",ans-last);
	return 0;
}
