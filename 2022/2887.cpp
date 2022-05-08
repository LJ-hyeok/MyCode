#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

struct node{
	int x,y,z;
};
vector<node> v;
int p[100001];

bool cmp(pt a, pt b){
	return a.c < b.c;
}

int find(int x){
	if(x==p[x])	return x;
	return p[x] = find(p[x]);
}

int main(){
	int N;
	cint >> N;
	for(int i=0;i<N;i++){
		int a,b,c;
		cin >> a >> b >> c;
		v.push_back((node){a,b,c});
	}
}
