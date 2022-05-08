#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	int N;
	scanf("%d",&N);
	
	int a[N+1];
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	
	int b;
	scanf("%d",&b);
	
	int cnt=0;
	for(int i=0;i<N;i++){
		if(b<a[i]){
			printf("%d",i+1);
			cnt++;
			break;
		}
		
		
	}
	if(cnt==0)
			printf("%d",N+1);
	return 0;
}
