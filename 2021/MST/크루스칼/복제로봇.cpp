#include<stdio.h>
using namespace std;
char arr[53][53];


int main(){
	int N, M;
	int Sx,Sy;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)	scanf("%s",&arr[i]);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			printf("%c",arr[i][j]);
	}
	
	
	return 0;
}
