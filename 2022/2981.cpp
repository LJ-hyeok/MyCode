#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int arr[101];
vector<int> v;

void solve(int x){
	for(int i=1;i<=(int)sqrt(x);i++)
		if(x%i==0)
			v.push_back(i), v.push_back(x/i);

	sort(v.begin(),v.end());
	
	int tmp = 1;
	for(int i=0;i<v.size();i++){
		if(v[i]==tmp)	continue;
		cout << v[i] << " ";
		tmp = v[i];
	}
}

int gcd(int x,int y){
	if(x<y)	swap(x,y);
	while(y!=0){
		int tmp = x;
		x = y;
		y = tmp%y;
	}
	return x;
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	sort(arr,arr+n);
	
	int dis=arr[1]-arr[0];
	for(int i=1;i<n;i++)
		dis = gcd(arr[i]-arr[i-1] , dis);
	solve(dis);
	
}
//5
//14 
//17
//23 
//83
