//BOJ_2042
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
typedef long long ll;

ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end){
	if(start==end)	return tree[node] = arr[start];
	int mid = (start+end)/2;
	return tree[node] = init(arr,tree,node*2,start,mid) + init(arr,tree,node*2+1,mid+1,end);
}

void update(vector<ll> &tree, int node, int start, int end, int index, ll diff){
	if(!(start <= index && index <= end))	return;
	tree[node] += diff;
	if(start!=end){
		int mid = (start+end)/2;
		update(tree,node*2,start,mid,index,diff);
		update(tree,node*2+1,mid+1,end,index,diff);
	}
}

ll sum(vector<ll> &tree, int node, int start, int end, int left, int right){
	if(left>end || right<start)	return 0;
	if(left<=start && end<=right)	return tree[node];
	int mid = (start+end)/2;
	return sum(tree,node*2,start,mid,left,right) + sum(tree,node*2+1,mid+1,end,left,right);
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N,M,K;
	cin >> N >> M >> K;
	int h = (int)ceil(log2(N));
	int tree_size = 1<<(h+1);
	vector<ll> arr(N);
	vector<ll> tree(tree_size);
	
	for(int i=0;i<N;i++)	cin >> arr[i];
	init(arr,tree,1,0,N-1);
	
	for(int i=0;i<M+K;i++){
		int a;
		cin >> a;
		if(a==1){
			int b;
			ll c;
			cin >> b >> c;
			ll diff = c-arr[b-1];
			arr[b-1] = c;
			update(tree,1,0,N-1,b-1,diff);
		}
		if(a==2){
			int b,c;
			cin >> b >> c;
			cout << sum(tree,1,0,N-1,b-1,c-1) << '\n';
		}
	}
}
