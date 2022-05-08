#include<stdio.h>
int main(){
	while(true){
		for(int i=0;i<10;i++){
			printf("%d\n",i);
			if(i==5)
				break;
		}
		printf("=======================\n");
	}
	return 0;
}
