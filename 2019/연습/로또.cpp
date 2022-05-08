#include<iostream>
int a[50];
int i,k=1;
void Q(int x,int i){
	
	if(i>6){
		for(int i=0;i<6;i++)
			printf("%d ",a[i]);
		printf("\n");
		return;
	}
	
	Q(x+1,i+1);
	Q(x+1,i);
	
}
int main(){
	while (k!=0){
		scanf("%d",&k);
		for(int i=0;i<k;i++)
			scanf("%d",&a[i]);
	}
	Q(0,0);
}
