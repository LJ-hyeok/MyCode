#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
int n,m;
int chk[200003];
struct node{
	int a,b,c;
};
bool cmp(node a,node b){
	return a.c < b.c;
}
int find(int x){
	if(chk[x] == x)
		return x;
	return chk[x] = find(chk[x]);
}
vector<node> arr;
int main(){
	while(true){
		int T = 0, t = 0;
		arr.clear();
		memset(chk,0,sizeof(chk));
		scanf("%d%d",&n,&m);
		if(n==0 && m==0)
			break;
		
		for(int i=1;i<=n;i++)
			chk[i] = i;
			
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
		 	arr.push_back({a,b,c});
			T+=c;
		}
		
		sort(arr.begin(),arr.end(),cmp);
		
		for(int i=0;i<m;i++){
			int pre = find(arr[i].a);
			int next = find(arr[i].b);
			if(pre == next)
				continue;
			chk[pre] = next;
			t+=arr[i].c;
		}
		printf("%d\n",T-t);
	}
	return 0;
}
