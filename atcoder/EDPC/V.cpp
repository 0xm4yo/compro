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

using mint = modint;

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> g(n);
    mint::set_mod(m);
    rep(i,0,n-1){
        ll x,y;
        cin>>x>>y;
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<mint> dp(n);
    vector<bool> v(n);
    function<mint(ll)> f1 = [&](ll now){
        mint res = 1;
        v[now] = true;
        for (auto nex: g[now]){
            if (v[nex])continue;
            res *= (f1(nex) + 1);
        }
        return dp[now] = res;
    };
    f1(0);

    rep(i,0,n)v[i] = false;
    vector<mint> ans(n, 1);
    function<void(ll)> f2 = [&](ll now){
        if (v[now])return ;
        v[now] = true;
        ll sz = g[now].size();
        vector<mint> left(sz+1, 1),right(sz+1, 1);
        rep(i,0,sz) left[i+1] *= left[i] * (dp[g[now][i]]+1);
        rrep(i,sz-1,0) right[i] *= right[i+1] * (dp[g[now][i]]+1);
        ans[now] = left[sz];
        rep(i,0,sz){
            dp[now] = left[i] * right[i+1];
            f2(g[now][i]);
        }
        return ;
    };
    f2(0);
    
    rep(i,0,n) cout << ans[i].val() << endl;
    return 0;
}