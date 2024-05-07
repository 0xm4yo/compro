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
    string s;
    cin>>s;

    vector<vector<ll>>dp(n+1,vector<ll>(2, INF));
    dp[0][0] = 0;
    rep(i,1,n+1){
        if (s[i-1]=='.'){
            chmin(dp[i][0], dp[i-1][0]);
            chmin(dp[i][1], dp[i-1][0]+1);
            chmin(dp[i][1], dp[i-1][1]+1);
        }else{
            chmin(dp[i][1], dp[i-1][0]);
            chmin(dp[i][1], dp[i-1][1]);
            chmin(dp[i][0], dp[i-1][0]+1);
        }
    }
    cout << min(dp[n][0], dp[n][1]) << endl;    
    return 0;
}