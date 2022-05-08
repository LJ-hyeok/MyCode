#include<stdio.h>
int n,m;
int arr[10005];
int e;
int s;

int BS()
{
	int mid;
	int ans = 0;
	while(s<=e)
	{
		ans = 0;
		mid  = (s+e)/2;
		for(int i=0;i<n;i++)
		{
			if(arr[i] < mid)
				ans += arr[i];
			else
				ans += mid;
		}	
//		printf("%d\t%d\t%d\t%d\n",s,mid,e,ans);
		if(ans > m)
			e = mid - 1;
		else
			s = mid + 1;
	}
	return e;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		if(e<arr[i])
			e = arr[i];
	}
	scanf("%d",&m);
	
	printf("%d",BS());
	return 0;
}
