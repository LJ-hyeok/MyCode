#include<iostream>
int max,mid,min;
int cnt=0;
int chk=0;

void Q(int x,int y,int z){
	if(x>y){
		if(z>x){
			max=z;
			if(y>x){
				mid=y;
				min=x;
			}
			else{
				mid=x;
				min=y;
			}
		}
		else{
			max=x;
			if(y>z){
				mid=y;
				min=z;
			}
			else{
				mid=z;
				min=y;
			}
		}
	}
	
	else if(y>z){
		if(x>y){
			max=x;
			if(y>z){
				mid=y;
				min=z;
			}
			else{
				mid=z;
				min=y;
			}
		}
		else{
			max=y;
			if(x>z){
				mid=x;
				min=z;
			}
			else{
				mid=z;
				min=x;
			}
		}
	}
	
	else if(x>z){
		if(y>x){
			max=y;
			if(x>z){
				mid=x;
				min=z;
			}
			else{
				mid=z;
				min=x;
			}
		}
		else{
			max=z;
			if(y>x){
				mid=y;
				min=x;
			}
			else{
				mid=y;
				min=x;
			}
		}
	}
	else{
		max=z;
		if(y>x){
				mid=y;
				min=x;
			}
			else{
				mid=x;
				min=y;
			}
	}
	if(max<mid+min)
		return;
	if(max==x){
		if(chk==0){
			Q(max,mid,min+1);
			chk=1;
		}
		else{
			Q(max,mid+1,min);
			chk=0;
		}
	}
	if(max==y){
		if(chk==0){
			Q(mid+1,max,min);
			chk=1;
		}
		else(chk==1)
		{
			Q(mid,max,min+1);
			chk=0;
		}
		
	}
	if(max==z){
		if(chk==0){
			Q(mid+1,min,max);
			chk=1;
		}
		else{
			Q(mid,min+1,max);
			chk=0;
		}
	}
	cnt++;	
	
	
	

}

int main(){
	int a,b,c;

	scanf("%d %d %d",&a,&b,&c);
	Q(a,b,c);
	printf("%d",cnt);
	
	
}
