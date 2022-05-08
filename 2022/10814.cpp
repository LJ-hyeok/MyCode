#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct info{
	int age, num;
	string name;
};
info arr[100003];

bool cmp(info a, info b){
	if(a.age==b.age)
		return a.num < b.num;
	return a.age<b.age;
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i].age >> arr[i].name;
		arr[i].num = i;
	}
	sort(arr,arr+n,cmp);
	for(int i=0;i<n;i++)
		cout << arr[i].age << " " << arr[i].name << "\n";
}
