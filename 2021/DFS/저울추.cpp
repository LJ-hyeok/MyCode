#include<stdio.h>
int n;
int arr[10] = {1,3,9,27,81,243,729};
int Lchk[10];
int Rchk[10];
bool flag;
bool tmp;
void dfs(int idx,int left,int right)
{
	if(flag) return;
	if(idx > 7){	
		if(right-left == n)
		{
			printf("%d ",n);
			for(int i=0;i<7;i++)
				if(Lchk[i] == 1)
					printf("%d ",arr[i]);
			printf("0 ");
			for(int i=0;i<7;i++)
				if(Rchk[i] == 1)
					printf("%d ",arr[i]);
			printf("\n");
			flag = true;
		}
		return;
	}

		
		
	Lchk[idx] = 1;
	dfs(idx+1,left+arr[idx],right);
	Lchk[idx] = 0;
	Rchk[idx] = 1;
	dfs(idx+1,left,right+arr[idx]);
	Rchk[idx] = 0;
	dfs(idx+1,left,right);
}
int main()
{
	scanf("%d",&n);
	//
	dfs(0,0,0);
	

	
	return 0;
}
