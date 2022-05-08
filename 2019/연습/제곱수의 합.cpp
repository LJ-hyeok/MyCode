#include<stdio.h>
int arr[100000];

int chk=0;
int end=0;
void fn(int x)
{
	int tmp=1;
	while(end!=1)
	{
		
		if(tmp*tmp>x)
		{
			chk++;
			printf("%d ",tmp-1);
			fn(x-((tmp-1)*(tmp-1)));
		}
		if(tmp*tmp==x){
			chk++;
			printf("%d\n",tmp);
			end=1;
		}
		tmp++;
		
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	fn(n);
	printf("%d",chk);
	return 0;
}

// 12 ==> 3 1 1 1       (X)   2 2 2
// 43 ==> 6 2 1 1 1     (X)  
