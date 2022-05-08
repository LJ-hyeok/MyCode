#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int set[51];
int main(int argc, char** argv) 
{
	int x=1;
	while(1){
		int a,b;
		scanf("%d,%d",&a,&b);
		if(a==100 || b==100) break;
		if(set[a] == 0 && set[b] == 0)
			set[a]=set[b]=x++;
		else{
			if(set[a]==0) 
				set[a]=set[b];
			else
				set[b]=set[a];
			if(set[a]>a[b])
				set[a]=set[b];
			else
				set[b]=set[a];
		}	
			
		
	}
	return 0;
}
