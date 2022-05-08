#include<stdio.h>
int arr[1000][1000];
int fn()
{
	
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&arr[i][j]);
	printf("%d",fn(0,0));
	return 0;
}
