#include<stdio.h>
using namespace std;

int arr[70][70];

bool chk(int x,int y, int s){
	int cmp = arr[x][y];
	for(int i=x;i<x+s;i++)
		for(int j=y;j<y+s;j++)
			if(arr[i][j]!=cmp)
				return false;
	return true;
}

void dfs(int x,int y,int s){
	if(chk(x,y,s)){
		printf("%d",arr[x][y]);
		return;
	}
	printf("(");
	int t = s/2;
	dfs(x, y, t);
	dfs(x, y+t, t);
	dfs(x+t, y, t);
	dfs(x+t, y+t, t);
	printf(")");
}

int main(){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			scanf("%1d",&arr[i][j]);
	dfs(1,1,N);
}
