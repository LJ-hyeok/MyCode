#include<stdio.h>
int N,K;
int arr[101];
int plug[101];
int cnt(int a){
	int cnt=0;
	for(int i=a;i<a+N;i++)
		if(arr[i])
			cnt++;
	return cnt;
}
int main(){
	scanf("%d%d",&N,&K);
	int ans = 0;
	int a;
	for(int i=0;i<K;i++){
		scanf("%d",&arr[i]);
		if(arr[i]==a) arr[i] = 0;
		else a = arr[i];
	}

	for(int i=0;i<N;i++) plug[i] = arr[i];
	for(int i=N;i<K;i+=N){
		for(int j=0;j<N;j++){//»Ì±â 
			bool chk=false;
			for(int k=i;k<i+N;k++){
				if(plug[j]==arr[k]){
					chk = true;
					arr[k]=0;
				}
			}
			if(!chk)
				plug[j]=0;
			if(N>cnt(i)){
				for(int j=0;j<cnt(i);j++)
					if(
			}
		}
		
		printf("\n\n");
		for(int j=0;j<N;j++)
			printf("%d ",plug[j]);
			
		for(int j=0;j<N;j++){//²È±â  
			if(!plug[j]){
				for(int k=i;k<i+N;k++){
					if(arr[k]){
						plug[j]=arr[k];
						arr[k]=0;
						ans++;
						break;
					}
				}
			}
		}
		printf("\n");
		for(int j=0;j<N;j++)
			printf("%d ",plug[j]);
	}
	printf("\n\nans: %d",ans);
//	printf("%d",ans);

	return 0;
}
