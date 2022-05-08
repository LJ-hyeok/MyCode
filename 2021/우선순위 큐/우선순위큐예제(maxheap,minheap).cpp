#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int,vector<int>, less<int> > maxheap;
priority_queue<int,vector<int>, greater<int> > minheap;
priority_queue<int> pq;
int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int t;
    scanf("%d",&t);
    maxheap.push(t);
    minheap.push(t);
    pq.push(-t);
    printf("---M:%d   N:%d    pq:%d---\n",maxheap.top(),minheap.top(),-pq.top());
  }
  return 0;
}
