#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[1001];
bool chk[100000001];
int main(){
	int N;
	int ans;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+N);
	
	int hi=0,tmp=0;
	int lo=1;
	for(int i=0;i<N;i++){
		chk[arr[i]]=1;
		for(int j=1;j<=hi;j++){
			if(chk[j]){
				chk[j+arr[i]] = 1;
				tmp = max(tmp,j+arr[i]);
			}
			
//			printf("%d: %d\n",j,chk[j]);
		}
		hi = max(tmp,arr[i]);
	}
	
	
	//print
	bool flag = false;
	for(int i=1;i<=hi;i++){
		if(!chk[i]){
			flag = true;
			printf("%d",i);
		}
		if(flag)
			break;
	}
	if(!flag)
		printf("%d",hi+1); 
	return 0;
}
