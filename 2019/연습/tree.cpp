#include<stdio.h>
int tree[1000000];
int N,M;
int Max(void)
{
	int max = 0;
	for(int i=0;i<N;i++){
		if(tree[i]>max)
			max=tree[i];
	}
	return max;
}
int Cut(int max)
{
	int cnt=1;
	int ans;
	while (true)
	{
		ans=0;
		for(int i=0;i<N;i++){
			if(tree[i] >= max - cnt)
				ans+= tree[i]-(max-cnt);
		}
		if(ans>=M)
			return (max-cnt);
		cnt++;
	}
	
}
int main(){
	int max;
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d",&tree[i]);
	}
	max = Max();
	printf("%d",Cut(max));
	return 0;
}
