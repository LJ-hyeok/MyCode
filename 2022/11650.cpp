#include<iostream>
#include<algorithm>
using namespace std;

struct pt{
	int x,y;
};
pt arr[100003];

bool cmp(pt a, pt b){
	if(a.y==b.y)
		return a.x < b.x;
	return a.y < b.y;
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int a,b;
		cin >> arr[i].x >> arr[i].y;
	}
	sort(arr,arr+n,cmp);
	for(int i=0;i<n;i++)
		cout << arr[i].x << " " << arr[i].y << "\n";
}
