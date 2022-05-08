#include<stdio.h>
#include<conio.h> 
int main()
{
	printf("==================#수열 프로그램#====================\n") ;
	printf("원하는 수열의 번호 입력\n") ;
	printf("등차수열 (1) 등비수열(2)");
	int chk = getch();
	
//	printf("구하려는 값") ;
//	printf("n번째 항의 값(1) n번째 항까지의 합(2)");
	
	if(chk=='1' ){
		printf("\n\n수열: a + (n - 1)d\t(n=1,2,3,...) 일  때\n첫째항 a와 공차 d를 입력하세요\na: ");
		int a,d,n;
		scanf("%d",&a);
		printf("d: ");
		scanf("%d",&d);
		printf("n을 입력 하시오: ");
		scanf("%d", &n);
		printf("n번째 항은 %d입니다",a+(n-1)*d);
	}
	if(chk =='2')
		printf("\n2");
	
	
	
	return 0;
}
