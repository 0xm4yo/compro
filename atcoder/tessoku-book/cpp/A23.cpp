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
const ll INF = (ll)1e15;

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>a(m, vector<ll>(n));
    rep(i,0,m)rep(j,0,n)cin>>a[i][j];
    vector<vector<ll>> dp(m+1, vector<ll>(1<<n, INF));
    dp[0][0] = 0;
    rep(i,0,m)rep(j,0,1<<n){
        if (dp[i][j] == INF)continue;
        chmin(dp[i+1][j], dp[i][j]);
        ll temp = 0;
        rep(k,0,n){
            if (a[i][k]==0)continue;
            temp += 1<<k;
        }
        chmin(dp[i+1][j|temp], dp[i][j]+1);
    }
    if (dp[m][(1<<n)-1] == INF){
        cout << -1 << endl;
    }else{
        cout << dp[m][(1<<n)-1] << endl;
    }

    return 0;
}