#include <stdio.h>
int arr[3005];
int chk;
int tmp[5];
int m(int x,int y,int z)
{
	tmp[0]=x;
	tmp[1]=y;
	tmp[2]=z;
	int t=1000,t2=0,mid;
	for(int i=0;i<=2;i++)
	{
		if(tmp[i]<t)
			{
				t=tmp[i];
			}
		if(tmp[i]>t2)
			{
				t2=tmp[i];
			}
	}
	
	for(int i=0;i<=2;i++)
	{
		if(tmp[i]!=t && tmp[i]!=t2)
			mid = tmp[i];
		
	}
	
}
int main(void)
{
	int n,sum;
	scanf("%d",&n);
	for(int i=0;i<(3*n);i++)
		scanf("%d",&arr[i]);
	
	for(int i=0;i<(3*n);i+=3)
	{
		
		m(arr[i],arr[i+1],arr[i+2]);
		
	}
	return 0;
}
