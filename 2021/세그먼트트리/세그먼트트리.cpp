//���׸�Ʈ Ʈ��
//2042
#include<stdio.h>
#include<math.h> //log2(),ceil()
#include<vector>
using namespace std;
typedef long long ll;
//���׸�Ʈ Ʈ���� ������ ���� ���ϱ� ���� �� Ƚ���� lgN���� �ٲٴ� ����̴�.
//���׸�Ʈ Ʈ���� ���� ��� ������ ������ �Է¹޴� row data �̴�.
//���׸�Ʈ Ʈ���� ���� �ٲٴ� ������ O(lgN) �̰�, ���� ���ϴ� ������ O(lgN)�̴�.
//���� �츮�� ����ϴ� ����� ���� ���ϴµ� N�� �׸��� �߰��� �迭�� ���� �ٲٴ� ������ M ���̶� �ϸ� �� O(MN)�� �ɸ���
//M=100 �̰� N=2^20 �� ��쿡 O(MN) = 10 000 000
//O(MlgN)�� 100*20 = 2000�� �̴�.

/*
����� ���� �ڽ� ��ȣ = node*2
����� ������ �ڽ� ��ȣ = node*2+1
*/
//Ʈ�� �ʱ�ȭ
ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end){
    if(start == end) //���� ���
        return tree[node]=arr[start];
    int mid = (start+end)/2;
    return tree[node] = init(arr,tree,node*2,start,mid) + init(arr, tree, node*2+1,mid+1,end); //dfs
}

//Ʈ���� ������� ���� �����Ѵ�.
void update(vector<ll> &tree, int node, int start, int end, int index, ll diff){
    if(!(start<=index && index <= end)) //���࿡ index ���� start �� end ���̿� ������ ����.
        return;
    tree[node]+=diff; //diff �� ���� arr�� ������ ���� ��ȭ�� ���� �ǹ��Ѵ�.
    if(start!=end){
        int mid = (start + end) /2;
        update(tree, node*2,start,mid,index,diff); //�����ڽ�
        update(tree, node*2+1,mid+1,end,index,diff); //�������ڽ�
    }
}

ll sum(vector<ll> &tree, int node, int start, int end, int left, int right){
    //[left,right] �� [start,end] �� ��ġ�� �ʴ� ��� -> �� ���� ���� ���ϴ� ������ ������� ���
    if(left>end || right<start) return 0;
    //[left,right] �� [start,end]�� ������ �����ϴ� ��� -> �� ���ϰ��� �ϴ� ������ ������ ����
    if(left<=start && end<=right) return tree[node];
    int mid = (start+end)/2;
    //[start,end]��[left,right]�� ������ �����ϴ� ��� -> �� ���ϰ��� �ϴ� ���� �� �������ٴ� ũ���� �� ���ο� ���ϰ��� �ϴ� ���� �� ������ �ִ� ���
    return sum(tree,node*2,start,mid,left,right)+sum(tree,node*2+1,mid+1,end,left,right);
}

int main(){
    int n;
    int tree_height = (int)ceil(log2(n));
    int tree_size = 1<<(tree_height+1);
    vector<ll> tree(tree_size); //���׸�Ʈ Ʈ�� �迭
    vector<ll> arr(n+1); //�Է� ������ ���� �迭
    for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
    init(arr,tree,1,0,n-1);
    //3 -> 10
    update(tree, 1, 0, n-1, 3, 10-tree[3]);
    //2~7
    printf("%lld",sum(tree, 1, 0, n-1, 2,7));
    return 0;
}
