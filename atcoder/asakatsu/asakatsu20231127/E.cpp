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
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    rep(i,0,n)cin>>a[i];

    ll MAX = 60;
    vector<vector<ll>> dp(MAX+1, vector<ll>(2,-INF));
    dp[0][0] = 0;
    // smaller = 0: k を超える可能性あり
    rep(i,0,MAX)rep(smaller,0,2){
        if (dp[i][smaller]==-INF) continue;
        ll pos = 1LL<<(MAX-i-1);
        ll zero = 0;
        ll one = 0;
        rep(j,0,n){
            if (pos&a[j]) zero++;
            else one++;
        }
        if (smaller==0){
            if (k&pos){
                chmax(dp[i+1][0], dp[i][0] + pos*one);
                chmax(dp[i+1][1], dp[i][0] + pos*zero);
            }else{
                chmax(dp[i+1][0], dp[i][0] + pos*zero);              
            }
        }else{
            chmax(dp[i+1][1], dp[i][1] + pos*one);
            chmax(dp[i+1][1], dp[i][1] + pos*zero);
        }
    }
    ll ans = max(dp[MAX][0], dp[MAX][1]);
    cout << ans << endl;
    return 0;
}