#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e2+1,M=50+1,mod=1e9+7,MOD=1e9+7;
#define Fast ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
int dp[N][N];
int w[N],v[N];
int n;
int fun(int i,int wa){
    if (i==n){
        return 0;
    }
    if (~dp[i][wa])
        return dp[i][wa];
    int take=0;
    if (wa-w[i]>=0){
        take= fun(i+1,wa-w[i])+v[i];
    }
    int leave= fun(i+1,wa);
    return dp[i][wa]= max(take,leave);
}
int main() {
    Fast
    int t = 1;
     cin >> t;
    while (t--) {
        int m;cin>>m>>n;
        memset(dp,-1,sizeof dp);
        for (int i = 0; i <n ; ++i) {
            cin>>w[i]>>v[i];
        }
        cout<<"Hey stupid robber, you can get "<<fun(0,m)<<".\n";
    }

    return 0;
}
