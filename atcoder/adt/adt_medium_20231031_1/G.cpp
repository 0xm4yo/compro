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

int main()
{
    ll n;
    cin>>n;
    ll x,y;
    cin>>x>>y;
    vector<vector<vector<ll>>> dp(310,vector<vector<ll>>(310, vector<ll>(310,INF)));
    dp[0][0][0] = 0;

    rep(i,0,n){
        ll a,b;
        cin>>a>>b;
        rep(j,0,301)rep(k,0,301){
            if (dp[i][j][k]==INF)continue;
            chmin(dp[i+1][j][k], dp[i][j][k]);
            chmin(dp[i+1][min((ll)300,j+a)][min((ll)300,k+b)], dp[i][j][k]+1);
        }
    }
    ll ans = INF;
    rep(j,x,301)rep(k,y,301){
        chmin(ans, dp[n][j][k]);
    }
    if (ans==INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}