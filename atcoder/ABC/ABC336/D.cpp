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
    vector<ll> a(n+2);
    rep(i,1,n+1)cin>>a[i];
    
    vector<ll> dp(n+2), dp2(n+2);
    rep(i,1,n+1){
        dp[i] = dp[i-1] + 1;
        chmin(dp[i], a[i]);
    }

    rrep(i,n,1){
        dp2[i] = dp2[i+1] + 1;
        chmin(dp2[i], a[i]);
    }
    
    ll ans = 0;
    rep(i,1,n+1){
        ll temp = min(dp[i], dp2[i]);
        chmax(ans, temp);
    }
    cout << ans << endl;

    
    return 0;
}