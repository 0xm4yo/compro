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
const ll INF = numeric_limits<ll>::max();

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>a(m),b(m);
    rep(i,0,m)cin>>a[i];
    rep(i,0,m)cin>>b[i];
    rep(i,0,m){ a[i]--; b[i]--; }
    dsu uf(n*2);
    rep(i,0,m){
        uf.merge(a[i],b[i]+n);
        uf.merge(b[i],a[i]+n);
    }
    bool flag = true;
    rep(i,0,n){
        if (uf.same(i,i+n)) flag = false;
    }
    YesNo(flag);
    return 0;
}