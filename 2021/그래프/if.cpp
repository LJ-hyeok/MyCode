#include<stdio.h>
int main()
{
	
	int g;
	scanf("%d", &g);
	if(90<=g && g<=100)
	{
		printf("A");
	}	
	else if(80<=g && g<=89)
	{
		printf("B");
	}
	else if(70<=g && g<=79)
	{
		printf("C");
	}
	else if(60<=g && g<=69)
	{
		printf("D");
	}
	else if(0<=g && g<=59)
	{
		printf("F");
	}
}


