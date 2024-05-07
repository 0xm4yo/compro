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
    ll n;
    cin>>n;
    ll sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    vector<ll>x(n+2),y(n+2),r(n+2);
    rep(i,0,n)cin>>x[i]>>y[i]>>r[i];
    dsu uf(n+2);
    x[n] = sx;
    y[n] = sy;
    x[n+1] = tx;
    y[n+1] = ty;
    auto f = [&](ll a, ll b){
        ll d2 = (x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]);
        if (d2>(r[a]+r[b])*(r[a]+r[b])) return false;
        if (d2<(r[a]-r[b])*(r[a]-r[b])) return false;
        return true;
    };
    rep(i,0,n+2)rep(j,i+1,n+2){
        if (f(i,j)) uf.merge(i,j);
    }
    YesNo(uf.same(n,n+1));

    return 0;
}