#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)1e18+10;

using mint = modint998244353;

int main()
{
    ll n;
    cin>>n;
    vector<vector<mint>> dp(11, vector<mint>(n+1, 0));
    rep(i,1,10) dp[i][0] = 1;
    rep(j,0,n)rep(i,0,10){
        if (i==0) continue;
        dp[i-1][j+1] += dp[i][j];
        dp[i][j+1] += dp[i][j];
        dp[i+1][j+1] += dp[i][j];
    }
    mint ans = 0;
    rep(i,1,10) ans += dp[i][n-1];
    cout << ans.val() << endl;

    return 0;
}