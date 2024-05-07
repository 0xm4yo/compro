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
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    vector<vector<ll>>dp(n+1, vector<ll>(2,-INF));
    dp[0][0] = 0;
    rep(i,1,n+1){
        ll x = a[i-1];
        chmax(dp[i][0], dp[i-1][0] + x);
        chmax(dp[i][0], dp[i-1][1] - x);
        chmax(dp[i][1], dp[i-1][0] - x);
        chmax(dp[i][1], dp[i-1][1] + x);
    }
    ll ans = dp[n][0];
    cout << ans << endl;

    return 0;
}