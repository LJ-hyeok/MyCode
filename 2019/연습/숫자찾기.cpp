#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAX = 100005;
int A[MAX],B[MAX];
int n,m;
void chk(int x){
	int s = 0;
	int e = n;
	while(s<=e){
		int mid = (s+e)/2;
		if(A[mid]==x){
			printf("1\n");
			return;
		}
		else if(A[mid]>x) e = mid-1;
		else s = mid+1;
	}
	printf("0\n");
	return;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	sort(A,A+n);
	scanf("%d",&m);
	for(int i=0;i<m;i++) scanf("%d",&B[i]);
	for(int i=0;i<m;i++)
		chk(B[i]);
	return 0;
}
