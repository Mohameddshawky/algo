#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+1,M=50+1,mod=1e9+7,MOD=1e9+7;
#define Fast ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
ll add(const ll &a, const ll &b) {
    return (a + b + 2 * mod) % mod;
}
string s;
ll dp[N];
int n;
ll fun(int i){
    if (i==n) return 1;
   ll &ret=dp[i];
    if (~ret)return ret;
    ll ans=0;
     ans= add(ans, fun(i+1));
    if (i<n-1&&s[i] == 'u' && s[i + 1] == 'u'){
        ans= add(ans, fun(i+2));
    }
    if (i<n-1&&s[i] == 'n' && s[i + 1] == 'n'){
        ans= add(ans, fun(i+2));
    }
    return ret=ans;

}
int main() {
    Fast
    int t = 4;//cin>>t;
    while (t--) {
        cin>>s; n=(int)s.size();
        bool f= false;
        for (int i = 0; i <n ; ++i) {
            f|=(s[i]=='m'||s[i]=='w');
        }

        memset(dp,-1,sizeof dp);
        ll ans=fun(0);
        cout << (f?ans-1:ans)<<"\n";

    }
    return 0;
}
