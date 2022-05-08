#include<stdio.h>
inline int max(int a, int b){return a>b?a:b;}
int N,M;
int arr[10001];
int l,h;
int BS()
{
	l = 0;
	int mid = (l+h)/2;
//	printf("%d\t%d\t%d\n",min,mid,max);
	while(l<=h){
		int sum = 0;
		for(int i=0;i<N;i++){
			if(arr[i] > mid)
				sum += mid;
			else
				sum += arr[i];
		}
		if(sum == M) return mid;
		if(sum > M)
			h = mid - 1;
		else	
			l = mid + 1;
		mid = (h+l)/2;
//		printf("%d\t%d\t%d\t%d\n",min,mid,max,sum);
	}
	return mid;
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
		h = max(h,arr[i]);
	}
	
	scanf("%d",&M);
	

		printf("%d",BS());
	
	return 0;
}
