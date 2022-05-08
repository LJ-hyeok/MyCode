#include<stdio.h>
long long h[10000005];
long long n,m;
int fd(long long min,long long max)
{
	long long mid;
	long long sum=0;
	mid=(min+max)/2;
	
	while(min<=max)
	{
		
		for(int i=0;i<n;i++)
			if(h[i]>mid)		
				sum+=h[i]-mid; 

		printf("\n%d\t%d\t%d\t%d\n",min,mid,max,sum);
		
		if(sum>m)
			min=mid+1;
		else if(sum<m)
			max=mid-1;
		mid=(min+max)/2;
		
		
		if(sum==m) 
			return mid;
			
		sum=0;
	}
//	printf("\n%d\t%d\t%d\t%d\n",min,mid,max,sum);
	return mid;
}
int main()
{
	int max;
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%lld",&h[i]);	
	printf("%d",fd(0,1000000000));
	return 0;
}
//4 8
//20 15 10 17   -> 15(x)
