#include<stdio.h>
int arr[100001];
int dx[100001];
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&arr[i]);
	for(int i=0;i<N-1;i++)
		dx[i] = arr[i+1] - arr[i];
		
	int cg, lo, hi;
	if(dx[0]<dx[1])	lo=dx[0], hi=dx[1];
	else			lo=dx[1], hi=dx[0];
	for(int j=hi;j>0;j--){
		if(hi%j==0 && lo%j==0){
			cg = j;
			break;
		}
	}
	for(int i=1;i<N-1;i++){
		if(dx[i]<cg) 	lo=dx[i], hi=cg;
		else			lo=cg, hi=dx[i];
		for(int j=hi;j>0;j--){
			if(hi%j==0 && lo%j==0){
				cg = j;
				break;
			}
		}
	}
	int ans = 0;
	for(int i=0;i<N-1;i++)
		ans+=dx[i]/cg-1;
	printf("%d",ans);//°¹¼ö¸¸ ÂïÀ¸¸éµÊ 
		
	return 0;
}
//1
//3
//7
//13
//
//2
//4
//6
