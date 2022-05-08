#include<stdio.h>
#include<algorithm>
using namespace std;
int N,M;
int main(){
	int a, b;
	int ma=1000, mb=1000;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d%d",&a,&b);
		ma = min(a,ma);
		mb = min(b,mb);
	}	
	
	int ans=0;
	while(N>0){
		if(ma<=6*mb){//ÆÐÅ°Áö<³¹°³ 
			if(N/6>0||ma<mb*N){
				ans+=ma;
				N-=6; 
			}
			else{
				ans+=mb;
				N--;
			}
		}
		else{//ÆÐÅ°Áö>³¹°³
			ans+=mb;
			N--;
		}
	}
	printf("%d",ans);
	return 0;
}
