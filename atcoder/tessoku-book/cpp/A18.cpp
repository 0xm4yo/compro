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

ll dp[70][22000] = {0};

int main()
{
    ll n,s;
    cin>>n>>s;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    dp[0][0] = 1;
    rep(i,0,n)rep(j,0,10010){
        dp[i+1][j] += dp[i][j];
        dp[i+1][j+a[i]] += dp[i][j];
    }
    YesNo(dp[n][s]);
    return 0;
}