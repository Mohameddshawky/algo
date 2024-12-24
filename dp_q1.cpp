#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e2+1,M=50+1,mod=1e9+7,MOD=1e9+7;
#define Fast ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
int arr[N];
int dp[N][M];
int n,ans=INT_MAX,s;
int fun(int i,ll sum){
    if (i==n) {
        ll sum2=s-sum;
        return abs(sum2-sum);
    }
    int &ret=dp[i][sum];
    if (~ret)return ret;
    int t= fun(i+1,sum+arr[i]);
    int l= fun(i+1,sum);
    return ret= min(t,l);
}
int main() {
    Fast
    int t = 1;cin>>t;
    while (t--) {
        cin >> n;
        ans=INT_MAX;s=0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            s += arr[i];
        }
        memset(dp,-1,sizeof dp);
        cout << fun(0,0)<<"\n";

    }
    return 0;
}
