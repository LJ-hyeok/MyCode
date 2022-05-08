#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m;
int arr[500001],arr2[500001];
int count(int a)
{
	int s = a, e = n -1;
	int mid;
	while(s<=e)
	{
		mid = (s+e)/2;
		if(arr[mid] == arr[a])
			s = mid + 1;
		else 
			e = mid - 1;
	}
	return e-a+1;
}
int BS(int x)
{
	int s = 0,e = n -1;
	int mid;
	while(s<=e)
	{
		mid = (s+e)/2;
		if(arr[mid] >= x)
			e = mid - 1;
		else 
			s = mid + 1;
		
	}
	if(x == arr[s])
		return count(s);
	else
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
		
	sort(arr,arr + n);
	
//	printf("%d",BS(arr2[3]));
	for(int i=0;i<m;i++)
		printf("%d ",BS(arr2[i]));
	return 0;
}
