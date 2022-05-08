#include <cstdio>
#include <algorithm>
using namespace std;
int L,K,C;
int arr[10010];
int length, pos;
bool calc(int len)
{
    int cnt = 0;
    pos = K+1;
    length = 0;
    for(int i=K; i>=0; i--)
    {
        if( arr[pos] - arr[i] > len )
        {
            if( pos == i+1 ) return false;
            length = max(length, arr[pos] - arr[i+1]);
            cnt++;
            pos = i+1;
            i++;
            if( cnt > C ) return false;
        }
    }
    length = max(length, arr[pos]);
    if( cnt < C ) pos = 1;
    return true;
}
int main()
{
    scanf(" %d %d %d", &L, &K, &C);
    for(int i=1; i<=K; i++) {
		scanf(" %d", &arr[i]);
	}
    arr[0] = 0;
    arr[K+1] = L;
    sort(arr, arr+K+2);
    int ans1, ans2;
    int lo=0, hi=2*L;
    while( lo+1 < hi )
    {
        int mid = (lo+hi)/2;
        if( calc(mid) )
        {
            hi = mid;
            ans1 = length;
            ans2 = arr[pos];
        }
        else
        {
            lo = mid;
        }
    }
    printf("%d %d", ans1, ans2);
    return 0;
}
