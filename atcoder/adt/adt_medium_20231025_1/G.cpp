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
const ll INF = numeric_limits<ll>::max();

using mint = modint998244353;

mint dp[3100][3100] = {(mint)0};

int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n),b(n);
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)cin>>b[i];

    dp[0][0] = 1;
    vector<mint>cum(3100);

    rep(i,1,n+1){
        rep(j,0,3010) cum[j] = 0;
        rep(j,0,3010) cum[j+1] = cum[j] + dp[i-1][j];
        ll x = a[i-1];
        ll y = b[i-1];
        rep(j,x,y+1){
            dp[i][j] += cum[j+1];
        }
    }
    mint ans = 0;
    rep(j,0,3010) ans += dp[n][j];
    cout << ans.val() << endl;
    return 0;
}