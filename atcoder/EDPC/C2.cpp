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

int main()
{
    ll n;
    cin>>n;
    vector<vector<ll>>abc(n,vector<ll>(3));
    rep(i,0,n)rep(j,0,3) cin>>abc[i][j];
    vector<vector<ll>>dp(3, vector<ll>(n+1, 0));
    rep(i,0,n){
        rep(j,0,3){
            rep(k,0,3){
                if (j==k)continue;
                chmax(dp[j][i+1], dp[k][i] + abc[i][j]);
            }
        }
    }
    ll ans = 0;
    rep(i,0,3) chmax(ans, dp[i][n]);
    cout << ans << endl;
    return 0;
}