#include<iostream>
#include<algorithm>
using namespace std;
int N,H;
int down[200001];
int up[200001];
int cmp(int a,int b){
	if(a<=b)
		return a;
	if(b<a)
		return b;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> H;
	for(int i=0;i<N/2;i++){
		cin >> down[i];
		cin >> up[i];
	}
		
	sort(up,up+(N/2));
	sort(down,down+(N/2));
	
	for(int i=0;i<N/2;i++)
		cout << up[i] << " ";
	cout << "\n";
	for(int i=0;i<N/2;i++)
		cout << down[i] << " ";
	int cnt = 0, mid = H/2+1;
	int res = 0, resN = 0;
	bool first = true;
	
	while(cnt!=mid){
		int upSum = 0, downSum = 0;	
		for(int i=0;i<N/2;i++){
			if(down[i]>=cnt+1)
				downSum++;
			if(H-up[i]<cnt+1)
				downSum++;
			if(up[i]>=cnt+1)
				upSum++;
			if(H-down[i]<cnt+1)
				upSum++;
		}
		
		if(first){
			res = cmp(upSum,downSum);
			first = false;
		}
		int tmp = cmp(upSum,downSum);
		if(tmp<res){
			res = tmp;
			resN=0;
		}
		if(res == upSum)
			resN++;
		if(res == downSum)
			resN++;
		cnt++;
	}
	cout << 
	cout << res << " " <<resN;
	return 0;
}
/*
14 6
1
3
4
2
2
4
3
4
3
3
3
2
3
3
*/
