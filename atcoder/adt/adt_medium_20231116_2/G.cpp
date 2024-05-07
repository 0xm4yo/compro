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

ll dp[110][110][110];

int main()
{
    ll n,k,d;
    cin>>n>>k>>d;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    rep(i,0,110)rep(j,0,110)rep(m,0,110) dp[i][j][m] = -INF;
    dp[0][0][0] = 0;
    rep(i,0,n)rep(j,0,k+1)rep(m,0,d){
        if (dp[i][j][m]==-INF)continue;
        chmax(dp[i+1][j][m], dp[i][j][m]);
        chmax(dp[i+1][j+1][(m+a[i])%d], dp[i][j][m]+a[i]);
    }
    if (dp[n][k][0]==-INF) cout << -1 << endl;
    else cout << dp[n][k][0] << endl;

    return 0;
}