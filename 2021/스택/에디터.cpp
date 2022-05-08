#include<iostream>
#include<stack>
#include<string>
using namespace std;
int M;
string sentence;
stack<char> lf;//left 사용시 에러  
stack<char> rt;
void print(){
	while(!lf.empty()){
		rt.push(lf.top());
		lf.pop();
	}
	while(!rt.empty()){
		cout<<rt.top();
		rt.pop();
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> sentence;
	cin >> M;
	for(int i=0;i<sentence.length();i++) lf.push(sentence[i]);
	
	char tmp, pu;
	for(int i=0;i<M;i++){
		cin >>tmp;
		if(tmp=='P'){
			cin >> pu;
			lf.push(pu);
		}
		if(tmp=='L'){
			if(!lf.empty()){
				rt.push(lf.top());
				lf.pop();
			}
		}
		if(tmp=='D'){
			if(!rt.empty()){
				lf.push(rt.top());
				rt.pop();
			}
		}
		if(tmp=='B'){
			if(!lf.empty())
				lf.pop();
		}
		
	}
	print();
	return 0;
}
