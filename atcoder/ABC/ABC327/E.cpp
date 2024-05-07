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

double dp[5100][5100];

int main()
{
    ll n;
    cin>>n;
    vector<ll>p(n);
    rep(i,0,n)cin>>p[i];
    double inf = -100000000000.0;
    rep(i,0,5100)rep(j,0,5100)dp[i][j] = inf;
    dp[0][0] = 0;
    rep(i,0,n)rep(j,0,n){
        if (dp[i][j] == inf)continue;
        chmax(dp[i+1][j], dp[i][j]);
        chmax(dp[i+1][j+1], dp[i][j]*0.9 + p[i]);
    }
    double ans = inf;
    rep(j,1,n+1){
        double ch = 0.0;
        rep(k,0,j) ch += pow(0.9,k);
        chmax(ans, dp[n][j]/ch - 1200.0/sqrt(j));
    }
    cout << fixed << setprecision(15) << ans << endl;
    
    return 0;
}