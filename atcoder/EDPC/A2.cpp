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
    vector<ll>h(n);
    rep(i,0,n)cin>>h[i];
    vector<ll>dp(n, INF);
    dp[0] = 0;
    rep(i,0,n-1){
        chmin(dp[i+1],dp[i]+abs(h[i]-h[i+1]));
        if (i+2<n) chmin(dp[i+2],dp[i]+abs(h[i]-h[i+2]));
    }
    cout << dp[n-1] << endl;
    return 0;
}