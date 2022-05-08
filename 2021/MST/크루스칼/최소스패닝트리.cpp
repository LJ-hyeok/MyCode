#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
  int f, t, w; //f -> t,w만큼의 비용이 소모된다.
};
vector<node> arr;
int chk[10002]; //노드가 MST에 포함이 되어있는지 확인
int res;
bool cmp(node A, node B){
  return A.w<B.w;
}
int find(int x){
  if(x == chk[x]) return x;
  return chk[x] = find(chk[x]);
}
int main(){
  int v,e;
  scanf("%d%d",&v,&e); //v - 노드의 갯수, e - 간선의 갯수
  for(int i=1;i<=v;i++) chk[i] = i; //Union Find 초기화
  for(int i=0;i<e;i++){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    arr.push_back({a,b,c});
  }
  //크루스칼 진행을 위해 간선 정렬
  sort(arr.begin(),arr.end(),cmp);
  //유니언 파인드를 통해서 사이클 찾기
  for(int i=0;i<e;i++){
    int pre = find(arr[i].f);//출발 노드
    int next = find(arr[i].t);//도착 노드
    if(pre == next) continue;
    chk[pre] = next;
    res+=arr[i].w;
  }
  printf("%d",res);
  return 0;
}
