#include<iostream>
#include<vector>
using namespace std;

int n;
int sz = 0;
int cnt = 0;
char arr[50][50];
vector<char> v;
vector<char> ans;

int R(int x,int y){
	int r = 0;
	int tmp = y;
	tmp++;
	while(0<=tmp && tmp<n && arr[x][tmp]!='U')	r++,tmp++;
	return r+y;
}

int L(int x,int y){
	int l = 0;
	int tmp = y;
	tmp--;
	while(0<=tmp && tmp<n && arr[x][tmp]!='U')	l++,tmp--;
	return y-l;
}

int move_y(int x,int y,int idx){
	if(y==idx)	return 0;
	else if(y<idx){
		for(int i=0;i<idx-y;i++)	v.push_back('R');
		return idx-y;
	}
	else if(y>idx){
		for(int i=0;i<y-idx;i++)	v.push_back('L');
		return y-idx;
	}
}

int move_x(){
	v.push_back('D');
	return 1;
}


bool safe(int x,int y){return x>=0 && y>=0 && x<n && y<n;}

void dfs(int d,int x,int y){
	int r = R(x,y);
	int l =	L(x,y);
	
	for(int i=l;i<y;i++)	v.push_back('L');
	for(int i=l;i<r;i++)	v.push_back('R');
	for(int i=y;i<r;i++)	v.push_back('L');
	int move_count = (y-l) + (r-l) + (r-y);
	
	int tmp = 0;
	for(int i=l;i<=r;i++)
		if(arr[x][i]=='D')
			tmp++;
	cnt+=tmp;
	
	if(x==n-1 && l<=n-1 && n-1<=r && sz<cnt)
	{
		sz = cnt;
		ans = v;
		for(int i=y;i<n-1;i++)	ans.push_back('R');
		cnt-=tmp;
		v.resize(v.size()-move_count);
		return;
	}
	
	for(int i=l;i<=r;i++){
		if(arr[x+1][i]!='U' && safe(x+1,i)){
			int d_cnt = move_y(x,y,i) + move_x();
			dfs(d+1,x+1,i);
			v.resize(v.size()-d_cnt);
		}
	}
	
	cnt-=tmp;
	v.resize(v.size()-move_count);
	return;
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> arr[i][j];
	dfs(0,0,0);
	for(int i=0;i<ans.size();i++)	cout << ans[i];
	return 0;
}
