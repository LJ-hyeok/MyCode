#include<iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
int L,T,N;
int icur,ans;
char ccur;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	cin >> L >> T >> N;
	for(int i=0;i<N;i++){
		cin >> icur >> ccur;
		if(ccur=='L'){
			ans=icur-T;
			if(ans<0){
				ans*=-1;
				int way=ans/L;
				if(way%2==0)	ans%=L;
				if(way%2==1)	ans=L-(ans%L); 
			}
		}
		if(ccur=='D'){
			ans=icur+T;
			if(ans>L){
				ans-=L;
				int way=ans/L;
				if(way%2==0)	ans=L-(ans%L);
				if(way%2==1)	ans%=L;
			}
		}
		pq.push(ans);
	}
	
	while(!pq.empty()){
		int cur = pq.top();
		pq.pop();
		cout << cur << " ";
	}
	
	return 0;
}

