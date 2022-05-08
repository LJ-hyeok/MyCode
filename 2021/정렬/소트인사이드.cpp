#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[12];
int main(){
	int N;
	scanf("%d",&N);
	int l = 1;
	int sl = 0;
	while(true){
		if(N/l){
			l *= 10;
			sl++;
		}
		else
			break;
	}
	l/=10;
	for(int i=0;i<sl;i++){
		arr[i] = N/l;
		N = N - (l*arr[i]);
		l/=10;
	}
	sort(arr,arr+sl);
	
	
	for(int i=sl-1;i>=0;i--)
		printf("%d",arr[i]);
	return 0;
}
