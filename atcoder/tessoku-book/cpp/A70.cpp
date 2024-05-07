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
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    vector<ll>x(m),y(m),z(m);
    rep(i,0,m)cin>>x[i]>>y[i]>>z[i];
        
    vector<vector<ll>>dp(m+1,vector<ll>(1<<n, INF));
    ll init = 0;
    rep(i,0,n){
        if (a[i]) init += 1<<i;
    }
    dp[0][init]=0;
    rep(i,0,m)rep(j,0,1<<n){
        chmin(dp[i+1][j], dp[i][j]);
        ll of = 0;
        of += 1<<(x[i]-1);
        of += 1<<(y[i]-1);
        of += 1<<(z[i]-1);
        chmin(dp[i+1][j^of], dp[i][j]+1);
    }
    ll ans = dp[m][(1<<n)-1];
    if (ans==INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}