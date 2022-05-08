#include<stdio.h>
int main(){
	int n;
	int a[1001];
	int d[1001];
	int max = 0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	
	for(int i=1;i<=n;i++){
		d[i] = 1;
		for(int j=1;j<i;j++){
			if(a[j]<a[i] && d[i]<d[j]+1)
				d[i] = d[j] + 1;
		}
		if(max<d[i])
			max = d[i];
	}
	printf("%d",max);
	
//	for(int i=1;i<=n;i++)
//		printf("%d ",d[i]);
	return 0;
}
