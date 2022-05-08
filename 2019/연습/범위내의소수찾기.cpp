#include <iostream>
int main(int argc, char** argv) 
{
	int m,n;
	int cnt;
	printf("M,N: ");
	scanf("%d,%d",&m,&n);
	for(int i=m;i<=n;i++){//3 <= i <= 9
		
		for(int j=2;j<i;j++){
			if(i%j==0)
				break;
			else{
				printf("%d ",i);
				cnt++;
				if(cnt==5)
					printf("\n");		
				break;
			}
		}
	
	}	

		

	return 0;
}
