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

int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n+5, INF),b(n+5, INF);
    rep(i,1,n) cin>>a[i];
    rep(i,2,n) cin>>b[i];
    vector<ll>dp(n+5,INF);
    dp[0] = 0;
    rep(i,0,n-1){
        chmin(dp[i+1], dp[i] + a[i+1]);
        chmin(dp[i+2], dp[i] + b[i+2]);
    }
    cout << dp[n-1] << endl;
    return 0;
}