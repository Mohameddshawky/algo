#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e2+1,M=1e2+1,mod=1e9+7,MOD=1e9+7;
#define Fast ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
int dp[N][N];
int d[N],gold[N];
int n,w;
vector<pair<int,int>>ans;
int fun(int i,int remt){
    if (i==n)return 0;

    int &ret=dp[i][remt];
    if (~ret)
        return ret;
    int take=0;
    if (remt - 3*w*d[i] >= 0){
        take= fun(i+1, remt - 3*w*d[i]) + gold[i];
    }
    int leave= fun(i+1, remt);
    return ret= max(take,leave);
}
void build_ans(int m) {
    int remt = m;
    for (int i = 0; i < n; ++i) {
        if (remt - 3 * w * d[i] >= 0 &&dp[i][remt]>= dp[i + 1][remt - 3 * w * d[i]] + gold[i]) {
            ans.emplace_back(d[i],gold[i]);
            remt -= 3 * w * d[i];
        }
    }

}
int main() {
    Fast
    int t = 1;
     //cin >> t;
    while (t--) {
        int m;cin>>m>>w>>n;
        memset(dp,-1,sizeof dp);
        for (int i = 0; i <n ; ++i) {
            cin >> d[i] >> gold[i];
        }
        cout<<fun(0,m)<<"\n";
        build_ans(m);
        cout<<ans.size()<<"\n";
        for(auto it:ans)
            cout<<it.first<<" "<<it.second<<"\n";
    }

    return 0;
}
