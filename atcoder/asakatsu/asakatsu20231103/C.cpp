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
    vector<string>s(n);
    rep(i,0,n)cin>>s[i];
    vector<vector<ll>>dp(2, vector<ll>(n+1));
    dp[0][0] = 1;
    dp[1][0] = 1;
    rep(i,0,n){
        if (s[i]=="AND"){
            dp[0][i+1] += dp[0][i]*2 + dp[1][i];
            dp[1][i+1] += dp[1][i];
        }else{
            dp[0][i+1] += dp[0][i];
            dp[1][i+1] += dp[0][i] + dp[1][i]*2;
        }
    }
    cout << dp[1][n] << endl;

    return 0;
}
