#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
typedef long long ll;

ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end){
    if(start == end)
        return tree[node]=arr[start];
    int mid = (start+end)/2;
    return tree[node] = init(arr,tree,node*2,start,mid) + init(arr, tree, node*2+1,mid+1,end);
}

void update(vector<ll> &tree, int node, int start, int end, int index, ll diff){
    if(!(start<=index && index <= end))
        return;
    tree[node]+=diff;
    if(start!=end){
        int mid = (start + end) /2;
        update(tree, node*2,start,mid,index,diff);
        update(tree, node*2+1,mid+1,end,index,diff);
    }
}

ll sum(vector<ll> &tree, int node, int start, int end, int left, int right){
    if(left>end || right<start) return 0;
    if(left<=start && end<=right) return tree[node];
    int mid = (start+end)/2;
    return sum(tree,node*2,start,mid,left,right)+sum(tree,node*2+1,mid+1,end,left,right);
}

int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int tree_height = (int)ceil(log2(n));
    int tree_size = 1<<(tree_height+1);
    vector<ll> tree(tree_size); //세그먼트 트리 배열
    vector<ll> arr(n+1); //입력 들어오는 숫자 배열
    
    for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
    init(arr,tree,1,0,n-1);
    
    for(int i=0;i<m+k;i++){
    	int a, b, c;
    	scanf("%d%d%d",&a,&b,&c);
    	if(a==1)	update(tree, 1, 0, n-1, b, c-tree[b]);
    	if(a==2)	printf("%lld\n",sum(tree, 1, 0, n-1, b,c));
    }
    
    return 0;
}
