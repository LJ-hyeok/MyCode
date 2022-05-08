#include<stdio.h>
int n,m;
int p[300001]; //UF -> 부모 저장
bool vis[300001]; // 각 서랍장에 술병이 놓여 있는지 아닌지 여부 판단
int find(int x){
  if(p[x] == x) return x;
  return p[x] = find(p[x]);
}
void Union(int a, int b){ // b 가 a의 부모
  a = find(a);
  b = find(b);
  p[a]=b;
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++) p[i] = i;
  for(int i=0;i<n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    if(!vis[a]){
      vis[a] = true;
      Union(a,b);
      printf("LADICA\n");
    }
    else if(!vis[b]){
      vis[b] = true;
      Union(b,a);
      printf("LADICA\n");
    }
    else if(!vis[find(p[a])]){
      vis[find(p[a])] = true;
      Union(a,b);
      printf("LADICA\n");
    }
    else if(!vis[find(p[b])]){
      vis[find(p[b])] = true;
      Union(b,a);
      printf("LADICA\n");
    }
    else{printf("SMECE\n");}
  }
  for(int i=1;i<=10;i++)
  	printf("%d ",vis[i]);
}
