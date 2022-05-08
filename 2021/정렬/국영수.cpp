#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct student{
	string name;
	int kor,eng,math;
};
bool cmp(student a,student b){
	if(a.kor==b.kor){
		if(a.eng==b.eng){
			if(a.math==b.math){
				if(a.name==b.name)
					return a.name>b.name;
				return a.name<b.name;
			}
			return a.math>b.math;
		}
		return a.eng<b.eng;
	}
	return a.kor>b.kor; 
}
student arr[100001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> arr[i].name;
		cin >> arr[i].kor >> arr[i].eng >> arr[i].math;
	}
	
	sort(arr,arr+N,cmp);
	
	for(int i=0;i<N;i++)
		cout << arr[i].name << "\n";
//	<<" "<<arr[i].kor<<" "<<arr[i].eng<<" "<<arr[i].math << endl; 
		
	return 0;
}
