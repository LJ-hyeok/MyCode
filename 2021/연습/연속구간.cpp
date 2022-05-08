#include<stdio.h>
int main(){
	for(int i=0;i<3;i++){
		int cnt = 1, ans = 0;
		int tmp;
		scanf("%1d",&tmp);
		for(int j=0;j<7;j++){
			int a;
			scanf("%1d",&a);
			if(a==tmp)
				cnt++;
			else if(a!=tmp){
				cnt=1;
				tmp = a;
			}
			if(ans<cnt)
				ans = cnt;
		}
		printf("%d\n",ans);
	}
	return 0;
}
