//BOJ_2003
#include<iostream>
using namespace std;

int arr[10000];

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N,M;
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> arr[i];

	int left=0, right=0, sum=arr[0], ans=0;
	
	while(left<=right && right<N){
		if(sum==M){
			ans++;
			sum+=arr[++right];
		}
		else if(sum<M)
			sum+=arr[++right];
		else if(sum>M){
			sum-=arr[left++];
			if(left>right){
				right=left;
				sum=arr[right];
			}
		}
	}
	
	cout << ans;
}
