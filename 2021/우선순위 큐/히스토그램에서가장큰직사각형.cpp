#include<iostream>
#include<stack>
using namespace std;
int arr[100001];
struct pt{
	int x,y;
};
stack<pt> s;
int main(){
	int a;
	while(true){
		cin >> a;
		if(a==0)
			break;
		s.push((pt){0,0});
		for(int i=0;i<a;i++){
			int tmp;
			cin >> tmp;
			if(s.top()>tmp){
				
			}
			
		}
		
	}
	return 0;
}
