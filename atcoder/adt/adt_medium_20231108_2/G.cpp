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
    vector<vector<ll>> g(n);
    vector<ll>a(n),b(n);
    rep(i,0,m){
        cin>>a[i]>>b[i];
        a[i]--;b[i]--;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    bool flag = true;
    rep(i,0,n)if(g[i].size()>2)flag=false;
    dsu uf(n);
    rep(i,0,m){
        if (uf.same(a[i],b[i]))flag=false;
        uf.merge(a[i],b[i]);
    }
    YesNo(flag);
    return 0;
}