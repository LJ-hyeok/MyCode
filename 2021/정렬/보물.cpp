#include<stdio.h>
#include<algorithm>
using namespace std;
int A[52];
int B[52];
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	for(int i=0;i<N;i++)
		scanf("%d",&B[i]);
	sort(A,A+N);
	sort(B,B+N);
	
	int sum = 0;
	for(int i=0;i<N;i++)
		sum+=A[i]*B[N-1-i];
	printf("%d",sum);
	return 0;
}
