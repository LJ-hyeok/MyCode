#include<iostream>
using namespace std;

const int mx = 2100000000;
int chk[10];

int count(int x){
	int tmp = 1;
	int ret = 0;
	while(tmp<=mx){
		ret++, tmp*=10;
		if(x/tmp == 0)	break;
	}
	return ret;
}

bool fn(int x){
	if(x<666)	return false;
	
	int tmp = 1;
	int e = count(x);
	for(int i=0;i<e-1;i++)	tmp*=10;
	
	for(int i=0;i<e;i++){
		chk[i] = x/tmp;
		x -= x/tmp*tmp;
		tmp/=10;
	}
	
	for(int i=0;i<=e-3;i++){
		if(chk[i]==6 && chk[i+1]==6 && chk[i+2]==6)
			return true;
	}
	return false;
}

int main(){
	int N;
	cin >> N;
	int cnt = 0;
	for(int i=1;i<=mx;i++){
		if(fn(i))	cnt++;
		if(cnt==N){
			cout << i;
			break;
		}
			
	}
}
