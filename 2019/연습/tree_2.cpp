#include<stdio.h>
int n,m;
int mid = 1000000000;
int arr[1000005];
bool cheak(int mid)
{
	for(int i=0;i<n;i++){
		if(mid<arr[i])
			return true;
		else
			return false;
		
	}
	
}
int Cut(void)
{
	int mid;
	int chk;
	int ans;
	while(1){
		
		if(cheak(mid)==1){
			for(int i=0;i<n;i++){
				if(arr[i]>mid){
					ans+=(arr[i]-mid);
				}
			}
			if(chk<=m){
				if(chk>ans)
					ans = chk; 
			}
			mid = mid/2;
			if()
		}
		else
			mid=mid/2;
	}
}
int main(void)
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)	
		scanf("%d",&arr[i]);
	Cut();
	return 0;
}
