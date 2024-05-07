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

using mint = modint1000000007;

int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,0,n)cin>>a[i];
    vector<vector<mint>>dp(n, vector<mint>(2)), cnt(n, vector<mint>(2));
    dp[0][0] = a[0];

    if (n==1){
        cout << a[0] << endl;
        return 0;
    }

    dp[1][0] = a[0] + a[1];
    dp[1][1] = a[0] - a[1];
    cnt[1][0] = 1;
    cnt[1][1] = 1;

    rep(i,2,n){
        dp[i][0] += dp[i-1][0] + a[i]*cnt[i-1][0];
        dp[i][0] += dp[i-1][1] + a[i]*cnt[i-1][1];
        dp[i][1] += dp[i-1][0] - a[i]*cnt[i-1][0];
        cnt[i][0] = cnt[i-1][0] + cnt[i-1][1];
        cnt[i][1] = cnt[i-1][0];
    } 
    mint ans = dp[n-1][0] + dp[n-1][1];
    cout << ans.val() << endl;

    return 0;
}