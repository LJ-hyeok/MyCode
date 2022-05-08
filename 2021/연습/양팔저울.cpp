#include<stdio.h>
using namespace std;
int N;
int arr[95];
int tmp[95];
bool dfs(int x, int idx){// s + left = right
//	int sr=0, sl=0;
	tmp[idx]=1;
	if(idx>N){//
		tmp[idx]=0;
		return 
	}
	dfs(x,idx+1);
	tmp[idx]=0;
	dfs(x,idx);
	
}	
main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	    scanf("%d",&arr[i]);
	    
	int cnt  = 0;
	for(int i=0;i<N;i++)
		if(!dfs(i,0,0))
			cnt++;
		
	printf("%d",cnt);
	return 0;
}
