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
    ll n,k;
    cin>>n>>k;
    vector<ll>h(n);
    rep(i,0,n)cin>>h[i];
    vector<ll>dp(n,INF);
    dp[0] = 0;
    rep(i,0,n){
        rep(j,1,k+1){
            if (i+j<n) chmin(dp[i+j], dp[i] + abs(h[i]-h[i+j]));
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}