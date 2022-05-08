#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
typedef long long ll;

const int mod = 1000000007;
const int mx = 200000;

/*ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end){
	if(start==end)	return tree[node] = arr[start];
	int mid = (start+end)/2;
	return tree[node] = ( init(arr,tree,node*2,start,mid)%mod * init(arr,tree,node*2+1,mid+1,end)%mod ) % mod; 
}

ll mul(vector<ll> &tree, int node, int start, int end, int left, int right){
	if(left>start || right<end)	return 1;
	if(left<=start&&end<=right)	return tree[node];
	int mid = (start+end)/2;
	return ( mul(tree,node*2,start,mid,left,right) * mul(tree,node*2+1,mid+1,end,left,right) ) % mod;
}*/

void update(vector<ll> tree, int node, int start, int end, int index, ll diff){
	if(!(start<=index&&index<=end))	return;
	if(start==end){
		tree[node] = diff;
		return;
	}
	int mid = (start+end)/2;
	update(tree,node*2,start,mid,index,diff);
	update(tree,node*2+1,mid+1,end,index,diff);
	tree[node] = ( tree[node*2] * tree[node*2+1] ) % mod;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N;
	cin >> N;
	int h = (int)ceil(log2(mx));
	int tree_size = 1<<(h+1); 
	vector<ll> arr(mx);
	vector<ll> tree(tree_size);
	for(int i=0;i<mx;i++)	arr[i] = 1;
	
	int pri, cur, cnt=1;
	ll V=0;
	cin >> pri;
	
	for(int i=1;i<N;i++){
		cin >> cur;
		V += (ll)((cur-pri)*cnt)%mod;
		arr[cur] = V;
		update(tree,1,0,mx-1,cur,V);
		//
		pri = cur;
		cnt++;
		
	}
	cout << tree[1];
}
