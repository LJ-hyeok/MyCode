#include<stdio.h>
int N;
int cnt;
int arr[105][105];
int tmp[105][105];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};


bool safe(int x,int y){
	return x>=0 && y>=0 && x<N && y<N;}
	
int maxi(int x,int y){
	return x>y?x:y;}
	
void dfs(int x,int y)
{
	for(int i=0;i<4;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(safe(tx,ty) && tmp[tx][ty] == 1 &&tmp[tx][ty] != cnt){
			tmp[tx][ty] = cnt;
			dfs(tx,ty);
		}
	}
}

int main()
{
	//input, setting max value
	int max = 0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j] > max)
				max = arr[i][j];
		}
	}
	
	int ans = 0;
	
	//0 < height <= max
	for(int t=0;t<=max;t++){
		//tmp[][] => 1 or 0
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(arr[i][j] - t <= 0)
					tmp[i][j] = 0;
				else	
					tmp[i][j] = 1;
			}
		}
		//dfs
		cnt = 1;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(tmp[i][j] == 1){
					cnt++;
					tmp[i][j] = cnt;
					dfs(i,j);
					ans = maxi(ans,cnt-1); //maximum of cnt
				}
			}
		}
	}
	
	printf("%d",ans);

	//Å© Áö·Ç´Ù  
	return 0;
}
