#include<iostream>
#include<algorithm>
using namespace std;
int N;
string arr[1001];
bool cmp(string a,string b){
	if(a.length()==b.length()){
		int asum=0,bsum=0;
		for(int i=0;i<a.length();i++){
			if(49<=(int)a[i] && (int)a[i]<=57)
				asum += ((int)a[i]-48);
			if(49<=(int)b[i] && (int)b[i]<=57)
				bsum += ((int)b[i]-48);
		}
		if(asum==bsum)
			return a<b;
		return asum<bsum;
	}
	return a.length()<b.length();
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> arr[i];
		
	sort(arr,arr+N,cmp);
	
	for(int i=0;i<N;i++)
		cout << arr[i] << "\n";
	
	return 0;
}
