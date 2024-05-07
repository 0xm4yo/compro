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
const ll INF = (ll)3e15;

int main()
{
    ll n,W;
    cin>>n>>W;
    vector<ll>w(n),v(n);
    rep(i,0,n)cin>>w[i]>>v[i];
    vector<vector<ll>>dp(n+1, vector<ll>(100010, INF));
    dp[0][0] = 0;
    rep(i,0,n)rep(j,0,100010){
        chmin(dp[i+1][j], dp[i][j]);
        if (dp[i][j]+w[i]<=W) chmin(dp[i+1][j+v[i]], dp[i][j]+w[i]);
    }
    ll ans = 0;
    rep(i,0,100010){
        if (dp[n][i]<=W) ans = i;
    }
    cout << ans << endl;

    return 0;
}