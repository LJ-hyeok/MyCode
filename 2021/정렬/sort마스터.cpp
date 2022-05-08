#include<stdio.h>
#include<algorithm>
using namespace std;
int N,M;
int A[200001];
int D[200001];
int BS(int x)
{
	int h=N-1,l=0;
	int mid = h;
	while(l<h){
		if(x<=A[mid])
			h = mid ;
		else
			l = mid + 1;
		mid =(h+l)/2;
	}
	
	if(A[mid] != x)
		return -1;
	return mid;
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	for(int i=0;i<M;i++)
		scanf("%d",&D[i]);
		
	sort(A,A+N);
	
	for(int i=0;i<M;i++)
		printf("%d\n",BS(D[i]));
		
	return 0;
}
