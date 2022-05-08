#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
typedef long long ll;

struct pt{ll value,lazy;};

ll init(vector<ll> &arr, vector<pt> &tree, int node, int start, int end){
    if(start == end)
        return tree[node].value=arr[start];
    int mid = (start+end)/2;
    return tree[node].value = init(arr,tree,node*2,start,mid) + init(arr, tree, node*2+1,mid+1,end);
}

void update(vector<pt> &tree, int node, int start, int end, int left, int right, ll d){
	
	
    if(left>end || right<start) return;
    tree[node]+=diff;
    
    if(start!=end){
        int mid = (start + end) /2;
        update(tree, node*2,start,mid,index,diff);
        update(tree, node*2+1,mid+1,end,index,diff);
    }
}

ll sum(vector<pt> &tree, int node, int start, int end, int left, int right){
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
    vector<pt> tree(tree_size);
    vector<ll> arr(n);
    
    for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
    init(arr,tree,1,0,n-1);
    
    for(int i=0;i<m+k;i++){
    	int a, b, c;
    	ll d;
    	scanf("%d",&a);
    	if(a==1){
    		scanf("%d%d%d",&b,&c,&d);
			update(tree, 1, 0, b-1, c-1, d);
		}
    	if(a==2){
    		scanf("%d%d",&b,&c);
			printf("%lld\n",sum(tree, 1, 0, n-1, b-1, c-1));
		}
    }
    
    return 0;
}
