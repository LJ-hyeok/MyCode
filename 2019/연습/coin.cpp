#include<stdio.h>
int n,k;
int arr[105];
void sort(){
	int temp;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(arr[j]<arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
}
int main(){
	int cnt;
	int i=0;
	scanf("%d %d",&n,&k);
	for(int i=0;i<3;i++)
		scanf("%d",&arr[i]);	
	sort();
	while(k!=0)
	{
		if(k>=arr[i]){
			k-=arr[i];
			cnt++;
		}
		else
			i++;
	}	
	printf("%d",cnt);
	
	return 0;	
}
 
