#include<stdio.h> 
int arr[10000][5];
int fn(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<j;i++)
		{
			
			arr[j][0] = fn(arr[j][i],arr[j][i-1]);
			
		}
	}
	
	return 0;
} 
