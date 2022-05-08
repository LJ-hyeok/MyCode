#include<stdio.h>

int main()
{
	int long long a,b,v;
	int h;
	scanf("%lld %lld %lld",&a,&b,&v);
	h = a - b;
	v = v - a;
	h = v/h;
	h= h+1;
	printf("%d",h);
	return 0;
}
