#include<stdio.h>
int B,n;
int a[25];
int ans=0;
void money(int x,int y)
{
	//printf("%d %d\t",x,y);
	if(y>B)
		return;
	if(x>n)
	{
		if(y>ans)
			ans=y;
		return;
	}
	money(x+1,y+a[x]);
	money(x+1,y);
}

int main(void)
{
	scanf("%d %d",&B,&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	money(0,0);
	printf("%d",ans);
	
	return 0;
}
