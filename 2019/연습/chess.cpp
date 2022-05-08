#include<stdio.h>
int n;
int a[15][15];
int chk=1;
int ans=0;
//r = row = За, c = column =  ї­ 


bool check(int r,int c){
	for(int i=1;i<=n;i++){
		if(a[r][i]==1) return false;
		if(a[i][c]==1) return false;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[r+j][i]==1) return false;
			if(a[r][i+j]==1) return false;
		}
	}
}

void queen(int x)
{
	if(x>n){
		ans++;
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(check(x,i)){
			a[x][i]=1;
			queen(x+1);
			a[x][i]=0;
		}	
	}
}

int main(void)
{
	scanf("%d",&n);
	queen(1);
	printf("%d",ans);
	return 0;	
}
