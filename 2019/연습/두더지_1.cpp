#include <iostream>
int S[35][35];
int cnt=1;
int n;
bool safe(int a, int b){
	return a>=0 && a<n&& b>=0 && b<n;
}

int F(int a,int b){
	S[a][b]=cnt;
	//printf("hi");
	if(safe(a+1,b) && S[a+1][b]==1){
		F(a+1,b);
	}
	if(safe(a-1,b) && S[a-1][b]==1){
		F(a-1,b);
	}
	if(safe(a,b+1) && S[a][b+1]==1){
		F(a,b+1);
	}
	if(safe(a,b-1) && S[a][b-1]==1){
		F(a,b-1);
	} 
	
	
	
}

int main(int argc, char** argv)
{

	scanf("%d",&n);
	
 	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			scanf("%d",&S[i][j]);
	}
	
	printf("\n\n");
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(S[i][j]==1){
				cnt++;
				F(i,j);
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d ",S[i][j]);
		printf("\n");
	}
	return 0;
}

/*
7
0 1 1 0 1 0 0
0 1 1 0 1 0 1
1 1 1 0 1 0 1
0 0 0 0 1 1 1
0 1 0 0 0 0 0
0 1 1 1 1 1 0
0 1 1 1 0 0 0
*/
