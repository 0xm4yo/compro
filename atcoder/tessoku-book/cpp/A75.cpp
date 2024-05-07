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

ll dp[110][150000] = {-INF};

int main()
{
    ll n;
    cin>>n;
    dp[0][0] = 0;
    vector<pair<ll,ll>> dt;
    rep(i,0,n){
        ll t,d;
        cin>>t>>d;
        dt.push_back({d,t});
    }
    sort(all(dt));
    rep(i,0,n){
        auto [d,t] = dt[i];
        rep(j,0,145000){
            if (dp[i][j] == -INF) continue;
            chmax(dp[i+1][j], dp[i][j]);
            if (j+t<=d) chmax(dp[i+1][j+t], dp[i][j]+1);
        }
    }
    ll ans = 0;
    rep(j,0,145000) chmax(ans, dp[n][j]);
    cout << ans << endl;

    return 0;
}