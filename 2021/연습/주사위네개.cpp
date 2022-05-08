#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int arr[7];
int main(){
	int N;
	scanf("%d",&N);
	int ans = 0;
	for(int i=0;i<N;i++){
		memset(arr,0,sizeof(arr));
		int sum = 0;
		for(int j=0;j<4;j++){
			int a;
			scanf("%d",&a);
			arr[a]++;
		}//input
		
		bool chk1=false;
		for(int j=1;j<=6;j++){
			if(arr[j]==4){
				sum = 50000+(j*5000);
				chk1 = true;
				break;
			}	
			else if(arr[j]==3){
				sum = 10000+(j*1000);
				chk1 = true;
				break;
			}	
			else if(arr[j]==2){
				int chk2=0;
				for(int k=j+1;k<=6;k++)
					if(arr[k] == 2)
						chk2 = k;
				if(chk2)
					sum = 2000+(j*500)+(chk2*500);
				if(!chk2)
					sum = 1000+(j*100);
				chk1 = true;
				break;
			}
		}
		if(!chk1){
			int tmp;
			for(int j=6;j>0;j--){
				if(arr[j]){
					tmp = j;
					break;
				}
			}
			sum = tmp*100;
		}
		if(sum>ans)
			ans = sum;
	}
	printf("%d",ans);
	return 0;
}


