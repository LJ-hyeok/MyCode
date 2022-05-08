#include<stdio.h>
#include<stack>
using namespace std;
typedef long long ll;
struct pt{
  ll h;
  int idx;
};
ll max(ll a, ll b){return a>b?a:b;}
int main(){
  while(true){
    int n;
    scanf("%d",&n);
    ll ans = 0;
    if(n==0) break;
    stack<pt> s;
    s.push((pt){0,0});
    for(int i=1;i<=n;i++){
      ll x;
      scanf("%lld",&x);
      while(s.top().h>x){
        pt cur = s.top();
        s.pop();
        ans = max(ans, cur.h * (i-1-s.top().idx));
      }
      s.push((pt){x,i});
    }
    while(s.top().h){
      pt cur = s.top();
      s.pop();
      ans = max(ans, cur.h * (n - s.top().idx));
    }
    printf("%lld\n",ans);
  }
  return 0;
}
