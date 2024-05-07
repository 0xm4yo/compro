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
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n),b(m);
    rep(i,0,n)cin>>a[i];
    rep(i,0,m)cin>>b[i];
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,INF));
    dp[0][0] = 0;
    rep(i,0,n+1)rep(j,0,m+1){
        if (i<n) chmin(dp[i+1][j],dp[i][j]+1);
        if (j<m) chmin(dp[i][j+1],dp[i][j]+1);
        if (i<n&&j<m){
            ll c = 1;
            if (a[i]==b[j]) c = 0;
            chmin(dp[i+1][j+1],dp[i][j]+c);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}