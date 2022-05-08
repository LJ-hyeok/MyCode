#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[10002];
int main(){
	int N;
	scanf("%d",&N);
	int t = 0,cnt = 0;
	for(int i=1;i<=N;i++){
		int a;
		scanf("%d",&a);
		arr[a]++;
	}
	for(int i=1;i<=10000;i++){
		if(arr[i]!=0)
			for(int j=0;j<arr[i];j++)
				printf("%d ",i);
	}
	


	return 0;
}
