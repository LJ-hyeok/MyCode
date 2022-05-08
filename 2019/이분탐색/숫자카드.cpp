#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[500005],arr2[500005];
int n,m;

int BS(int x)
{
	int s = 0;
	int e = n-1;
	int mid;
	while(s<=e)
	{
		mid = (s+e)/2;
		
		if(x < arr[mid])
			e = mid - 1;
		if(x > arr[mid])
			s =  mid + 1;
		if(x == arr[mid])
			return 1;
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	scanf("%d",&m);	
	for(int i=0;i<m;i++)
		scanf("%d",&arr2[i]);
		
	sort(arr,arr+n);
	
	for(int i=0;i<m;i++)
		 printf("%d ",BS(arr2[i]));
	
	
	return 0;
}
