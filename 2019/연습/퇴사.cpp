#include<stdio.h>
int t[16],p[16];
int n,ans;
int max(int x,int y)
{
	if(x>y)
		return x;
	else 
		return y;
}

void Q(int i,int tmp)
{
	
	if(i==n+1)
	{
		ans=max(ans,tmp);
		return;
	}
	if(i+t[i]<=n+1)
		Q(i+t[i],tmp+p[i]);
	Q(i+1,tmp);

/*	if(i+t[i]>n)
	{
		printf("%d %d\n",ans,tmp);
		if(i+t[i]==n+1)
			tmp+=p[i];
		if(tmp>ans)
			ans=tmp;
		return;
	}
	Q(i+t[i],tmp+p[i]);
	Q(i+1,tmp);
*/
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&t[i],&p[i]);

	Q(1,0);

	printf("%d",ans);
	return 0;
}
