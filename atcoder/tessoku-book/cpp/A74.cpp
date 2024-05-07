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

ll p[110][110] = {0};

ll op(ll a, ll b){ return a+b; };
ll e(){ return 0; };

int main()
{
    ll n;
    cin>>n;
    rep(i,0,n)rep(j,0,n)cin>>p[i][j];
    vector<ll> h,w;
    rep(i,0,n)rep(j,0,n){
        if (p[i][j]) h.push_back(p[i][j]-1);
    }
    rep(j,0,n)rep(i,0,n){
        if (p[i][j]) w.push_back(p[i][j]-1);
    }
    segtree<ll,op,e> segh(n),segw(n);
    ll ans = 0;
    for (auto x: h){
        ans += segh.prod(x+1, n);
        segh.set(x, 1);
    }
    for (auto x: w){
        ans += segw.prod(x+1, n);
        segw.set(x, 1);
    }
    cout << ans << endl;

    return 0;
}