#include<stdio.h>
int main(){
	int ans = 0;
	int x,y;
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			int a;
			scanf("%d",&a);
			if(a > ans){
				x = i,y = j;
				ans = a;
			}
		}
	}
	printf("%d\n%d %d",ans,x,y);
	return 0;
}
