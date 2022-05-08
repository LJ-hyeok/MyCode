#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int arr[13][7];
int chk[13][7];
bool tmar[7];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int tmp,cnt=1;
queue<int> q;
void print()
{
	cout << "\n";
	for(int i=0;i<12;i++){
		for(int j=0;j<6;j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
}
bool safe(int x, int y){ return x>=0&&y>=0&&x<12&&y<6;}
void counting(int x, int y){
	chk[x][y]=cnt;
	cnt++;
	for(int i=0;i<4;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(safe(tx,ty)&&arr[tx][ty]==tmp&&chk[tx][ty]==0)
			counting(tx,ty);
	}
}
void erase(int x, int y){
	arr[x][y]=9;
	tmar[y]=1;
	for(int i=0;i<4;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(safe(tx,ty)&&arr[tx][ty]==tmp)
			erase(tx,ty);
			
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);//입력을 int로  
	int ans=0;
	char a;
	for(int i=0;i<12;i++){
		for(int j=0;j<6;j++){
			cin >> a;
			if(a=='R') arr[i][j] = 1;
			if(a=='G') arr[i][j] = 2;
			if(a=='B') arr[i][j] = 3;
			if(a=='P') arr[i][j] = 4;
			if(a=='Y') arr[i][j] = 5;
			if(a=='.') arr[i][j] = 0;
		}
	}
	bool judge = true;
	while(judge){
		int cur = 0, pri = 0;
		judge = false;
		for(int i=0;i<12;i++){
			for(int j=0;j<6;j++){
				if(arr[i][j]&&chk[i][j]==0){
					tmp = arr[i][j];
					counting(i,j);//4개 이상인지 숫자 세보기 
					pri = cur;
					cur = cnt - 1;
					if(cur-pri>=4){ // 4개 이상이면 지우기 
						judge = true;
						erase(i,j);
					}
					
				}
			}
		}
		
		// 내리기
		for(int i=0;i<6;i++){
			if(tmar[i]==1){
				int cnt9=0;
				for(int j=11;j>=0;j--){
					if(arr[j][i]==9)
						cnt9++;
					else
						q.push(arr[j][i]);
					
				}
				for(int j=11;j>=cnt9;j--){
					arr[j][i]=q.front();
					q.pop();
				}
				for(int j=cnt9-1;j>=0;j--)
					arr[j][i]=0;
			}
		}
		memset(chk,0,sizeof(chk));
		memset(tmar,0,sizeof(tmar));
		cnt = 0;
		ans++;
	}
	cout << ans-1;
	return 0;
}
