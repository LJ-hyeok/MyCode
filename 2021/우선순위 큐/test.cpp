#include<stdio.h>
int main(){
	int dp[5][5] = {1,1,1,3,1,};
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++)
			printf("%d ",dp[i][j]);
		printf("\n");
	}
}
