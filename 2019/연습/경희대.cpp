#include<stdio.h> 
int Cnt(int x){
		if(x==10000)
			return 5;
		else if(x>=1000)
			return 4;
		else if(x>=100)
			return 3;
		else if(x>=10)
			return 2;
		else if(x>0)
			return 1;
}
int main(){
	int a,b;
	int A,B;
	int ans1,ans2,ans3,ansF;
	int a1[10],b1[10];
	scanf("%d %d",&a,&b);
	ans1=a+b;
	A=Cnt(a);
	B=Cnt(b);
	
	for(int i=0;i<A;i++){
		if(A==5){
			ans2=ans2+1;
		}
		if(A==4){
			ans2=(a%10)*1000+((a/10)%10)*100+((a/100)%10)*10+(a/1000);
		}
		if(A==3){
			ans2=(a%10)*100+((a/10)%10)*10+(a/100);
		}
		if(A==2){
			ans2=(a%10)*10+(a/10);
		}
		if(A==1){
			ans2=a;
		}
	}
	for(int i=0;i<B;i++){
		if(B==5){
			ans3=1;
		}
		if(B==4){
			ans3=(b%10)*1000+((b/10)%10)*100+((b/100)%10)*10+(b/1000);
		}
		if(B==3){
			ans3=(b%10)*100+((b/10)%10)*10+(b/100);
		}
		if(B==2){
			ans3=(b%10)*10+(b/10);
		}
		if(B==1){
			ans3=b;
		}
	}
	if(ans1-(ans2+ans3)<0){
		ansF=(-1)*(ans1-(ans2+ans3));
	}
	else
		ansF=ans1-(ans2+ans3);
	printf("%d",ansF);
	
}
