#include<stdio.h>
int n;
int a[] = {1,3,9,27,81,243,729};
int chk[10];
bool flag=false;
void S(int x,int y,int z)
{
	if(flag) return;
	if(x>7){	
		if(y==z)
		{
			printf("%d ",n);
			flag = true;
			for(int i=0;i<7;i++)
			{
				if(chk[i]==1)
					printf("%d ",a[i]);
			}
			printf("0 ");
			for(int i=0;i<7;i++)
			{
				if(chk[i]==2)
					printf("%d ",a[i]);
			}
		}
		return ;
	}
	chk[x]=1;
	S(x+1,y+a[x],z);
	chk[x]=2;
	S(x+1,y,z+a[x]);
	chk[x]=0;
	S(x+1,y,z);
	
}
int main(void)
{
	scanf("%d",&n);
	S(0,n,0);
	return 0;
}
