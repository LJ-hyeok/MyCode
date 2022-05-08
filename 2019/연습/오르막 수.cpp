#include<stdio.h>
int arr[11];

void climb(int x)
{
	for(int j=1;j<x;j++)
		for(int i=2;i<=10;i++)
			arr[i]=((arr[i]+arr[i-1])%10007);
	return;
}
int main(void)
{
	int n;
	int sum=0;
	scanf("%d",&n);
	for(int i=1;i<=10;i++)
		arr[i]=1;
		
	climb(n);
	if(n>0)
	{
		for(int i=1;i<=10;i++)
		sum+=arr[i];
	}
	
	printf("%d\n",sum%10007);
	return 0;
}
