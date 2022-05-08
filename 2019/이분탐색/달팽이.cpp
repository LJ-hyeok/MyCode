#include<stdio.h>
int main()
{
	int a,b,v;
	scanf("%d %d %d",&a,&b,&v);
	int h;
	int s=0, e = v -a;
	int mid;
	while(s<=e)
	{
		mid = (s+e)/2;
		
		h = (mid -1)*(a-b) + a;
		
//	printf("%d %d %d %d\n",s,mid,e,h);
		
		if(h >= v)
			e = mid - 1;
		else
			s = mid + 1;
	} 
	printf("%d",s);
	 
}
