#include<stdio.h>
#include<conio.h> 
int main()
{
	printf("==================#���� ���α׷�#====================\n") ;
	printf("���ϴ� ������ ��ȣ �Է�\n") ;
	printf("�������� (1) ������(2)");
	int chk = getch();
	
//	printf("���Ϸ��� ��") ;
//	printf("n��° ���� ��(1) n��° �ױ����� ��(2)");
	
	if(chk=='1' ){
		printf("\n\n����: a + (n - 1)d\t(n=1,2,3,...) ��  ��\nù°�� a�� ���� d�� �Է��ϼ���\na: ");
		int a,d,n;
		scanf("%d",&a);
		printf("d: ");
		scanf("%d",&d);
		printf("n�� �Է� �Ͻÿ�: ");
		scanf("%d", &n);
		printf("n��° ���� %d�Դϴ�",a+(n-1)*d);
	}
	if(chk =='2')
		printf("\n2");
	
	
	
	return 0;
}
