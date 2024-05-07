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
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>g(n);
    dsu uf(n+n);
    rep(i,0,m){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        uf.merge(u,v+n);
        uf.merge(u+n,v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rep(i,0,n){
        if (g[i].size()==0)continue;
        if (uf.same(i,i+n)){
            cout << 0 << endl;
            return 0;
        }
    }

    auto v = uf.groups();
    vector<bool> vis(n);
    ll ans = n*(n-1)/2;
    ans -= m;
    for (auto vv: v){
        ll sz = vv.size();
        ll st = vv[0];
        if (st>=n) st-=n;
        if (vis[st])continue;
        ll cnt = 0;
        for (auto x: vv){
            if (x>=n){
                x-=n;
                cnt++;
            }
            vis[x] = true;
        }
        ans -= cnt*(cnt-1)/2;
        ans -= (sz-cnt)*(sz-cnt-1)/2;
    }
    cout << ans << endl;
    return 0;
}