#include<iostream>
int n;
int a[10]={1,3,9,27,81,243,729};
int chk[7];
void A(int i,int l,int r){

	if(i>7)
		return;

	if(l==r){
		for(int i=0;i<7;i++){
			if(chk[i]==1)
				printf("%d ",a[i]);
		}
		printf("0 ");
		for(int i=0;i<7;i++){
			if(chk[i]==2)
				printf("%d ",a[i]);
			}
		return;
	}

	chk[i]=1,A(i+1,l+a[i],r);
	chk[i]=2,A(i+1,l,r+a[i]);
	chk[i]=0,A(i+1,l,r);
}

int main(){
	scanf("%d",&n);
	printf("%d ",n);
	A(0,n,0);
}
