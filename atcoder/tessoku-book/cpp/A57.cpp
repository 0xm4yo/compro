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

ll dp[70][200000] = {0};

int main()
{
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n+1);
    rep(i,1,n+1)cin>>a[i];
    rep(i,1,n+1)dp[0][i] = a[i];
    rep(i,1,65) rep(j,1,n+1){
        dp[i][j] = dp[i-1][dp[i-1][j]];
    }
    while(q){
        q--;
        ll x,y;
        cin>>x>>y;
        rep(i,0,60){
            if (y&(1LL<<i)) x = dp[i][x];
        }
        cout << x << endl;
    }
    return 0;
}