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

using mint = modint998244353;

int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    vector<vector<mint>> dp(n+1, vector<mint>(1<<11));
    dp[0][1] = 1;
    rep(i,0,n){
        mint inva = a[i];
        inva = inva.inv();
        rep(j,0,1<<11){
            if (dp[i][j]==0)continue;
            rep(k,1,min(10LL,a[i])+1){
                ll j2 = j | ((j<<k)&((1<<11)-1));
                dp[i+1][j2] += dp[i][j] * inva;
            }
            if (a[i]>10){
                dp[i+1][j] += dp[i][j] * (a[i]-10) * inva;
            }
        }
    }
    mint ans = 0;
    rep(i,1<<10,1<<11){
        ans += dp[n][i];
    }
    cout << ans.val() << endl;
    return 0;
}