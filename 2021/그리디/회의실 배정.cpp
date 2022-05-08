#include<stdio.h>
#include<algorithm>
using namespace std;
int N;
struct pt{
	int x,y;
};
bool cmp(pt a,pt b){
	if(a.y == b.y)
		return a.x < b.x;
	return a.y<b.y;
}
pt arr[100001];
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d",&arr[i].x,&arr[i].y);
	}
	sort(arr,arr+N,cmp);
	
	int cnt = 1;
	int cp = arr[0].y;
	for(int i=1;i<N;i++){
		if(arr[i].x >= cp){
			cp = arr[i].y;
			cnt++;
		}
			
	}
	printf("%d",cnt);
	
	return 0;
}
