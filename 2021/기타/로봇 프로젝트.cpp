#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int x, n, N;
int l[1000003];

int BS(int x){
	int left = 0;
	int right = n-1;
	while(left<=right){
		int mid = (left+right)/2;
		if(mid==x)
			break;
		if(l[x]+l[mid]==N)
			return l[mid];
		else if(l[x]+l[mid]>N)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	while(true){
		int ans1=0, ans2=0;
		int comp = 0;
		memset(l,0,sizeof(l));
		bool flag = false;
		cin >> x >> n;
		if(cin.eof() == true) break;
		for(int i=0;i<n;i++)
			cin >> l[i];
	
		N=x*10000000;
		sort(l,l+n);
	
		for(int i=0;i<n;i++){
			int tmp = BS(i);
			if(tmp==-1)	continue;
			flag = true;
	
			int tmp_l = tmp - l[i];
			if(tmp_l<0)	tmp_l*=-1;
	
			if(comp<=tmp_l){
				comp = tmp_l;
				if(tmp>l[i])	ans1=l[i],ans2=tmp;
				else	ans1=tmp,ans2=l[i];
			}		
		}
		
		if(flag)
			cout << "yes " << ans1 << " " << ans2 <<"\n";
		if(!flag)
			cout << "danger" <<"\n";
		}
	return 0;
}
//1 2 9999998 9999999
