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

using mint = modint1000000007;

int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    vector<vector<mint>> dp(n+1, vector<mint>(k+2));
    dp[0][0] = 1;
    dp[0][1] = -1;
    rep(i,0,n){
        rep(j,1,k+2){
            dp[i][j] += dp[i][j-1];
        }
        rep(j,0,k+1){
            dp[i+1][j] += dp[i][j];
            dp[i+1][min(j+a[i], k)+1] -= dp[i][j];
        }
    }
    rep(j,1,k+2){
        dp[n][j] += dp[n][j-1];
    }
    cout << dp[n][k].val() << endl;
    return 0;
}