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
    vector<double>p(n);
    rep(i,0,n)cin>>p[i];
    vector<vector<double>> dp(n+1, vector<double>(n+1,0));
    dp[0][0] = 1.0;
    rep(i,0,n)rep(j,0,n){
        if (dp[i][j]==0)continue;
        dp[i+1][j] += dp[i][j]*(1.0-p[i]);
        dp[i+1][j+1] += dp[i][j]*p[i];
    }
    double fr = 0.0;
    rep(j,0,n+1){
        if (j>n/2) fr += dp[n][j];
    }
    cout << fixed << setprecision(15) << fr << endl; 
    
    return 0;
}