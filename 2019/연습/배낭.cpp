#include<iostream>
int n,W;
int wi[100],vi[100];
int wsum,vsum;
int ans;

void A(int i,int wsum,int vsum){
	if(wsum>W)
		return;
	if(i>=n){
		if(vsum>ans)
			ans=vsum;
		return;
	}
	A(i+1,wsum+wi[i],vsum+vi[i]);
	A(i+1,wsum,vsum);


}
int main(){
	scanf("%d",&n);
	scanf("%d",&W);
	for(int i=0;i<n;i++){
		scanf("%d %d",&wi[i],&vi[i]);
	}
	A(0,0,0);
	printf("%d",ans);
	return 0;
}
