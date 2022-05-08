#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long int ll;

struct pt{ll h;int idx;};
stack<pt> s;

int main(){
	while(true){
		int n;
		ll ans=0;
		cin >> n;
		while(!s.empty())	s.pop();
		if(n==0)	break;
		s.push((pt){0,0});
		
		for(int i=1;i<=n;i++){
			int a;
			cin >> a;
			while(s.top().h>a){
				pt cur = s.top();
				s.pop();
				ans=max(ans,cur.h*(i-1-s.top().idx));
			}
			s.push((pt){a,i});
		}
		
		while(s.top().h){
				pt cur = s.top();
				s.pop();
				ans=max(ans,cur.h*(n-s.top().idx));
		}
		
		cout << ans << '\n';
	}
	return 0;
}
