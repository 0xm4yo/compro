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
    vector<ll>a(n),b(n);
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)cin>>b[i];
    dsu uf(n);
    rep(i,0,m){
        ll c,d;
        cin>>c>>d;
        c--;d--;
        uf.merge(c,d);
    }
    auto arr = uf.groups();
    bool flag = true;
    for (auto v: arr){
        ll ta = 0;
        ll tb = 0;
        for (auto x: v){
            ta += a[x];
            tb += b[x];
        }
        if (ta!=tb) flag = false;
    }
    YesNo(flag);
    return 0;
}