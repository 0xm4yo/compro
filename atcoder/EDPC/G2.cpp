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
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> g(n);
    vector<ll>indeg(n);
    rep(i,0,m){
        ll x,y;
        cin>>x>>y;
        x--;y--;
        g[x].push_back(y);
        indeg[y]++;
    }
    vector<ll>dp(n, -1);
    function<ll(ll)> dfs = [&](ll now){
        if(dp[now]!=-1) return dp[now];
        ll res = 0;
        for (auto nex: g[now]){
            chmax(res, dfs(nex));
        }
        dp[now] = res + 1;
        return res + 1;
    };
    ll ans = 0;
    rep(i,0,n){
        if (indeg[i]) continue;
        chmax(ans, dfs(i));
    }
    cout << ans-1 << endl;

    return 0;
}