#include<iostream>
#include<string.h>
using namespace std;
int R,C,N; 
int M[102][102],arr[102];
int tmar[102][102];
int tmchk[102];
int chk=1;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void print(){
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			if(M[i][j]==1)
				cout << "x";
			if(M[i][j]==0)
				cout <<".";
		}
		cout << "\n";
	}
}
bool safe(int x, int y){return x>0 && y>0 && x<=R && y<=C;}
void dfs(int x,int y){
	tmar[x][y]=chk;
	if(chk==2)
		tmchk[y]=1;
	for(int i=0;i<4;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(safe(tx,ty)&&M[tx][ty]&&!tmar[tx][ty])
			dfs(tx,ty);
	}
}
int main(){
	//===========================================================
	ios_base::sync_with_stdio(false);
	char a;
	cin >> R >> C;
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			cin >> a;
			if(a=='.')
				M[i][j] = 0;
			if(a=='x')
				M[i][j] = 1;
		}
	}
	cin >> N;
	for(int i=1;i<=N;i++) cin >> arr[i];
	//===========================================================
	int cnt = 1;
	while(cnt<=N){
		chk = 1;
		memset(tmar,0,sizeof(tmar));
		memset(tmchk,0,sizeof(tmchk));
		if(cnt%2==1){//홀= 왼쪽 
				for(int i=1;i<=C;i++){
					if(M[R-arr[cnt]+1][i]){
						M[R-arr[cnt]+1][i]=0;
						break;
					}
				}
			}	
			else{ //짝 = 오른쪽 
				for(int i=C;i>=1;i--){
					if(M[R-arr[cnt]+1][i]){
						M[R-arr[cnt]+1][i]=0;
						break;
					}
				}
			}
		for(int i=1;i<=C;i++){//1 층 
			if(M[R][i]&&!tmar[R][i]){
				dfs(R,i);
			}
		}
		for(int i=1;i<R;i++){//나머지 층  
			for(int j=1;j<=C;j++){
				if(M[i][j]&&!tmar[i][j]){
					chk++;
					dfs(i,j);
				}
			}
		}
		if(chk>1){
			for(int i=1;i<=C;i++){//2에서부터 바닥 또는 1 까지의 거리 
				if(tmchk[i]){
					int cheak=R+1;
					for(int j=R;j>=1;j--){
						if(tmar[j][i]==1)
							cheak = j;
						if(tmar[j][i]==2){
							tmchk[i] = cheak-j-1;
							break;
						}
					}
				}
			}
			int lo=101;
			for(int i=1;i<=C;i++){//거리중 최소값 
				if(tmchk[i]&&tmchk[i]<lo)
					lo=tmchk[i];
			}
			for(int i=1;i<=C;i++){//중력 
				if(tmchk[i]){
					for(int j=R;j>=1;j--){
						if(tmar[j][i]==2){
							M[j+lo][i] = 1;
							M[j][i]=0;
						}	
					}
				}
			}
		}
		cnt++;
	}
	print();
	return 0;
}
