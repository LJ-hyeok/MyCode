#include<iostream>
int main(){
	int n,m;
	int a[10];
	int cnt,t;
	scanf("%d",&m);
	scanf("%d",&n);
	for(int i=n-1;i>=0;i--){
		scanf("%d",&a[i]);
	}
	
	for(int i=0;i<n;i++){
		if(m>=a[i]){
		t=m/a[i];
		cnt+=t;
		m=m%a[i];
		}
	}
	printf("%d",cnt);
	
}
