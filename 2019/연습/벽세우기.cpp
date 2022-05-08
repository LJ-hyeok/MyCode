#include<iostream>
int A[15][15];
int N,M;
void dfs1(int i,int j){
	if(A[i][j]==2){
		return;
		
	}
	if(A[i][j]==0){
		A[i][j]==2;
	}
	dfs1(i+1,j)
	dfs1(i,j+1)
}



int main(){
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d",&A[i][j]);
		}
	}
	
	dfs1(0,0);
}
