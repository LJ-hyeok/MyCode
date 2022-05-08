#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int chk[1001];
struct node{
	int a,b,c;
};
vector<node> arr;
bool cmp(node a, node b){
	return a.c<b.c;
}
int find(int a){
	if(a == chk[a])
		return a;
	return chk[a] = find(chk[a]);
}
int main(){
	int N,M;
	int ans=0;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		arr.push_back({a,b,c});
	}
	for(int i=1;i<=N;i++)
		chk[i] = i;
	sort(arr.begin(),arr.end(),cmp);
	for(int i=0;i<M;i++){
		int pre = find(arr[i].a);
		int next = find(arr[i].b);
		if(pre==next)
			continue;
		chk[pre] = next;
		ans+=arr[i].c;
	}
	printf("%d",ans);
	return 0;
}
