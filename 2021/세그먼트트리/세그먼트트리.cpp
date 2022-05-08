//세그먼트 트리
//2042
#include<stdio.h>
#include<math.h> //log2(),ceil()
#include<vector>
using namespace std;
typedef long long ll;
//세그먼트 트리는 구간의 합을 구하기 위해 그 횟수를 lgN으로 바꾸는 방법이다.
//세그먼트 트리의 리프 노드 값들은 실제로 입력받는 row data 이다.
//세그먼트 트리는 수를 바꾸는 과정이 O(lgN) 이고, 수를 더하는 과정이 O(lgN)이다.
//원래 우리가 사용하던 방법은 수를 더하는데 N번 그리고 중간에 배열의 수를 바꾸는 과정이 M 번이라 하면 총 O(MN)번 걸린다
//M=100 이고 N=2^20 일 경우에 O(MN) = 10 000 000
//O(MlgN)은 100*20 = 2000번 이다.

/*
노드의 왼쪽 자식 번호 = node*2
노드위 오른쪽 자식 번호 = node*2+1
*/
//트리 초기화
ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end){
    if(start == end) //리프 노드
        return tree[node]=arr[start];
    int mid = (start+end)/2;
    return tree[node] = init(arr,tree,node*2,start,mid) + init(arr, tree, node*2+1,mid+1,end); //dfs
}

//트리의 리프노드 값을 갱신한다.
void update(vector<ll> &tree, int node, int start, int end, int index, ll diff){
    if(!(start<=index && index <= end)) //만약에 index 값이 start 와 end 사이에 없으면 리턴.
        return;
    tree[node]+=diff; //diff 는 원래 arr의 값에서 새로 변화한 값을 의미한다.
    if(start!=end){
        int mid = (start + end) /2;
        update(tree, node*2,start,mid,index,diff); //왼쪽자식
        update(tree, node*2+1,mid+1,end,index,diff); //오른쪽자식
    }
}

ll sum(vector<ll> &tree, int node, int start, int end, int left, int right){
    //[left,right] 와 [start,end] 가 겹치지 않는 경우 -> 즉 구간 합을 구하는 범위와 상관없는 경우
    if(left>end || right<start) return 0;
    //[left,right] 가 [start,end]를 완전히 포함하는 경우 -> 즉 구하고자 하는 구간합 구간에 포함
    if(left<=start && end<=right) return tree[node];
    int mid = (start+end)/2;
    //[start,end]가[left,right]를 완전히 포함하는 경우 -> 즉 구하고자 하는 구간 합 범위보다는 크지만 그 내부에 구하고자 하는 구간 합 범위가 있는 경우
    return sum(tree,node*2,start,mid,left,right)+sum(tree,node*2+1,mid+1,end,left,right);
}

int main(){
    int n;
    int tree_height = (int)ceil(log2(n));
    int tree_size = 1<<(tree_height+1);
    vector<ll> tree(tree_size); //세그먼트 트리 배열
    vector<ll> arr(n+1); //입력 들어오는 숫자 배열
    for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
    init(arr,tree,1,0,n-1);
    //3 -> 10
    update(tree, 1, 0, n-1, 3, 10-tree[3]);
    //2~7
    printf("%lld",sum(tree, 1, 0, n-1, 2,7));
    return 0;
}
