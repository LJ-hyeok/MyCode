#include <iostream>
#include<algorithm>
using namespace std;
int A[100005],B[100005];

int number(int a){
	int start=0,mid=0,end=100000;
	while(start<=end){
		mid=(start+end)/2;
		if(a==A[mid]) return 1;
		else if(a<A[mid]){
			end=mid-1;
		}
		else{
			start=mid+1;
		}
		}
		return 0;
		
}
int main(int argc, char** argv) 
{
	int N,M;
	scanf("%d",&N);
	
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
	} 
	sort(A,A+N);
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		scanf("%d",&B[i]);
	}
	
	
	for(int i=0;i<M;i++){
		printf("%d\n",number(B[i]));
		
	}
	return 0;
}
