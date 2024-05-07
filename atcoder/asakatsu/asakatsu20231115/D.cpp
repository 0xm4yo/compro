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

int main()
{
    ll n;
    cin>>n;
    vector<ll>x(n),y(n),z(n);
    rep(i,0,n) cin>>x[i]>>y[i]>>z[i];
    ll now = 0;
    ll tot = 0;
    rep(i,0,n){
        if (x[i]>y[i]) now += z[i];
        tot += z[i];
    }
    vector<vector<ll>>dp(n+1, vector<ll>(tot+1, INF));
    dp[0][0] = 0;
    rep(i,0,n)rep(j,0,tot+1){
        if (dp[i][j]==INF)continue;
        chmin(dp[i+1][j],dp[i][j]);
        if (x[i]>y[i])chmin(dp[i+1][j+z[i]],dp[i][j]);
        else chmin(dp[i+1][j+z[i]],dp[i][j]+(x[i]+y[i])/2+1-x[i]);
    }
    ll ans = INF;
    rep(i,tot/2+1, tot+1) chmin(ans, dp[n][i]);
    cout << ans << endl;


    return 0;
}