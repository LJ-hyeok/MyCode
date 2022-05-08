#include<stdio.h>
#include<algorithm>
using namespace std;
int N;
int P[1001];
void print(){
	printf("\n");
	for(int i=1;i<=N;i++)
		printf("%d ",P[i]);
	printf("\n");
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&P[i]);
	sort(P+1,P+1+N);
//	print();
	int tmp=0,sum=0;
	for(int i=1;i<=N;i++){
		tmp+=P[i];
		sum+=tmp;
	}
	printf("%d ",sum);
		
	return 0;
}
