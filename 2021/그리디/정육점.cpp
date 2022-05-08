#include<stdio.h>
#include<algorithm>
using namespace std;
int N,M;
struct pt{
	int x,y;
}arr[100001];
void print(){
	printf("\n");
	for(int i=0;i<N;i++)
		printf("%d %d\n",arr[i].x,arr[i].y);
	printf("\n");
}
bool cmp(pt a,pt b){
	if(a.y==b.y)
		return a.x>b.x;
	return a.y<b.y;
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%d%d",&arr[i].x,&arr[i].y);
	sort(arr,arr+N,cmp);
	
	int ans=0x7fffffff,sum = 0;
	int tmp = 0;
	bool flag=false;
	for(int i=0;i<N;i++){
		int curx = arr[i].x,cury = arr[i].y;
		sum+=curx;
		if(cury==arr[i-1].y)
			tmp += arr[i-1].y;
		else
			tmp = 0;
		if(sum>=M){
			ans = min(ans,cury+tmp);
			flag = true;
		}	
	}
//	print();
//	printf("%d ",sum);
	if(flag)
		printf("%d",ans);
	else
		printf("-1");
	return 0;
}
