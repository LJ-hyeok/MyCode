#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll arr[1000000];
ll dp[1000000];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++)    cin >> arr[i];
    dp[0] = arr[0];
    for(int i=1;i<n;i++)    dp[i] = max(dp[i-1]+arr[i], arr[i]);
    ll ans = -1e9;
    for(int i=0;i<n;i++) ans=max(ans,dp[i]);
    cout << ans;
    return 0;
}
