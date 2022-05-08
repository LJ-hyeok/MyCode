#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	int sum1=0,sum2=0;
	for(int i=0;i<N-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a%2!=0)
			sum1++;
	}
	printf("%d",min(sum1,N-sum1));
	return 0;
}
	
