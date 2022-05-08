#include<stdio.h>
#include<algorithm>
using namespace std;
struct info{
	int a,b,c;
};
bool cmp(info a,info b){
	return a.c >  b.c;
}
int chk[105];
info arr[105];
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d %d %d",&arr[i].a,&arr[i].b,&arr[i].c);
	sort(arr,arr+N,cmp);
	
	int cnt=0;
	for(int i=0;i<N;i++){
		if(cnt==3)
			break;
		if(chk[arr[i].a]>=2)
			continue;
		printf("%d %d\n",arr[i].a,arr[i].b);
		chk[arr[i].a]++;
		cnt++;
	}
	
	
	
	return 0;
}
