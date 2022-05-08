#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[500003];
int chk[8003];
vector<int> v;

int Round(double x){
	bool minus = false;
	if(x<0){
		x*=-1;
		minus = true;
	}
	double tmp = x-(int)x;
	if(tmp>=0.5)	return minus ? -1*((int)x+1) : (int)x+1;
	return minus ? -1*(int)x : (int)x;
}

int main(){
	int n;
	double sum = 0;
	
	cin >> n;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		sum+=a;
		arr[i] = a;
		chk[a+4000]++;
	}
	
	sort(arr,arr+n);
	
	int res1, res2, res3, res4;
	
	res1 = Round(sum/n);
	res2 = arr[n/2];
	
	int mx = 0;
	for(int i=-4000;i<=4000;i++)
		if(chk[i+4000] > mx)
			mx = chk[i+4000];
	for(int i=-4000;i<=4000;i++)
		if(chk[i+4000]==mx)
			v.push_back(i);
	if(v.size() > 1)	res3 = v[1];
	else				res3 = v[0];

	res4 = arr[n-1] - arr[0];

	cout << res1 << "\n";
	cout << res2 << "\n";
	cout << res3 << "\n";
	cout << res4;
}
