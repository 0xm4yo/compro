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
    rep(i,0,n)cin>>x[i]>>y[i]>>z[i];
    auto f = [&](ll a, ll b){
        return abs(x[a]-x[b]) + abs(y[a]-y[b]) + max(0LL,z[b]-z[a]);
    };

    vector<vector<ll>> cost(n, vector<ll>(n, INF));
    rep(i,0,n)rep(j,0,n) cost[i][j] = f(i,j);
    rep(k,0,n)rep(i,0,n)rep(j,0,n){
        chmin(cost[i][j], cost[i][k] + cost[k][j]);
    }

    vector<vector<ll>>dp(1LL<<n, vector<ll>(n, INF));
    dp[0][0] = 0;
    rep(i,0,1LL<<n)rep(j,0,n){
        if (i==0 && j!=0) continue;
        rep(k,0,n){
            if (i&(1LL<<k))continue;
            chmin(dp[i+(1LL<<k)][k], dp[i][j]+cost[j][k]);
        }
    }
    cout << dp[(1LL<<n)-1][0] << endl;


    return 0;
}