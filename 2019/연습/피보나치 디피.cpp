#include <stdio.h>
int cnt0=0,cnt1=0;

int fibonacci(int n) {
    if (n == 0) {
        cnt0++;
        return 0;
    } else if (n == 1) {
        cnt1++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
int main(void)
{
	int a;
	int b;
	scanf("%d",&a);
	for(int i=0;i<a;i++)
	{
		scanf("%d",&b);
		printf("%d",fibonacci(b));
	}
	return 0;
}
