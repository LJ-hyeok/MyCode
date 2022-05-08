#include <iostream>
int main(int argc, char** argv) 
{
	int i,j,k;
	int a,cnt;
	int t=0,c=0;
	printf("원하는 그램을 입력하세요:");
	scanf("%d",&a);
	for(i=1;i<11;i++){
		for(j=1;j<11;j++){
			for(k=1;k<11;k++){
				if(i*2+j*3+k*5 = a){
					printf("%d\t%d\t%d\n",i,j,k);
					cnt++;
				}
			}
		}
	}
		printf("경우의 수 = %d",cnt);
	return 0;
}
