#include<iostream>
#include<map>
using namespace std;

map<int,int> mymap; //<user, time>

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N,M;
	cin >> N >> M;
	bool flag = true;
	for(int i=0;i<M;i++){
		int a,b,c;
		cin >> a >> b >> c;
		if(!c){
			if(!mymap.count(b)){
				mymap[b] = a;
			}
			else{
				flag = false;
				break;
			}
		}
		if(c){
			if(!mymap.count(b)){
				flag = false;
				break;
			}
			else{
				if(a - mymap[b] < 60){
					flag = false;
					break;
				}
				mymap.erase(b);
			}
		}
	}
	
	if(mymap.size())
		flag = false;
		
	if(flag)	cout << "YES";
	if(!flag)	cout << "NO";
	return 0;
}
