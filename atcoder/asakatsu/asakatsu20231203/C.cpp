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
    dsu uf(n);
    vector<ll>indeg(n);
    rep(i,0,m){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
        uf.merge(u,v);
        indeg[u]++;
        indeg[v]++;
    }
    bool flag = true;
    if (uf.groups().size()!=1) flag = false;
    rep(i,0,n){
        if (indeg[i]>2) flag = false;
    }
    ll cnt = 0;
    rep(i,0,n)if(indeg[i]==1) cnt++;
    if (cnt!=2) flag = false;
    YesNo(flag);
    return 0;
}