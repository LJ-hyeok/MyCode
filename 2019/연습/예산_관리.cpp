#include<iostream>
int B,n;
int a[25];
int sum,i;
int ans;
void A(int i,int sum){
	if(sum>B)
		return;
	if(i>n){
		if(sum>ans)
			ans=sum;
		return;
	}
	A(i+1,sum+a[i]);
	A(i+1,sum);
}
	
	
int main(){

	scanf("%d",&B);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	A(0,0);
	printf("%d",ans);
	return 0;
	
}
