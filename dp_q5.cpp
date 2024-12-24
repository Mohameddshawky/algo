#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e1+1,M=50+1,mod=1e9+7,MOD=1e9+7;
#define Fast ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()

int n,arr[N],dp[N][N];
int fun(int i,int last){
    if (i>=n)return 0;
    int &ret=dp[i][last];
    if (~ret)return ret;
    ret= fun(i+1,last);
    if (arr[i]>last)
        ret= max(ret, fun(i+1,arr[i])+1);
    return ret;
}
int main() {
    Fast
    int t = 1;
    //cin >> t;
    while (t--) {
        cin>>n;
        for (int i = 0; i <n ; ++i) {
            cin>>arr[i];
        }
        memset(dp,-1,sizeof dp);
        cout<<fun(0,0)<<"\n";
    }
    return 0;
}
