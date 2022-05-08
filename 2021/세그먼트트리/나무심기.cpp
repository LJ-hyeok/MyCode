#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
typedef long long ll;

const int mod = 1000000007;
const int mx = 200000;

ll solve(vector<int> &in, vector<ll> &arr, int N){
	ll sum = arr[in[0]];
	for(int i=1;i<in.size();i++)
		sum = (sum*arr[in[i]])%mod;
	return sum;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N;
	cin >> N;
	vector<ll> arr(mx+1);
	vector<int> in;
	
	int pri, cur, diff,V=0, cnt=1;
	cin >> pri;
	
	for(int i=1;i<N;i++){
		cin >> cur;
		in.push_back(cur);
		diff = V + (cur-pri)*cnt;
		arr[cur] = diff;
		//
		pri = cur;
		V = arr[cur];
		cnt++;
	}
	cout << solve(in,arr,N);
}
