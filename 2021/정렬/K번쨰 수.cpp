#include<stdio.h>
#include<algorithm>
int A[5000001];
using namespace std;
int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	sort(A,A+N);
	printf("%d",A[K-1]);
	return 0;
}
