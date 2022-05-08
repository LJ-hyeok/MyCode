#include<stdio.h>
int arr[1001];
int main(){
	int sum = 0;
	int ans=0,cnt=0;
	for(int i=0;i<10;i++){
		int a;
		scanf("%d",&a);
		sum += a;
		arr[a]++;
	}
	for(int i=10;i<=1000;i+=10){
		if(cnt<arr[i]){
			cnt = arr[i];
			ans = i;
		}
	}
	printf("%d\n%d",sum/10,ans);
	return 0;
}
