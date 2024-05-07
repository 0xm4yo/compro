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

using mint = modint998244353;

struct S
{
    mint now;
    S(){ now = (mint)0; }
    S(mint x){ now = x; }
};
S op(S l, S r){
    return S();
}
S e(){
    return S();
}

struct F
{
    mint a,b;
    F(){ a = 1; b = 0; }
    F(mint x, mint y){ a = x; b = y; }
};

S mp(F f, S x){
    x.now *= f.a;
    x.now += f.b;
    return x;
}

F comp(F f, F g){
    g.a *= f.a;
    g.b *= f.a;
    g.b += f.b;
    return g;
}

F id(){ return F(); }

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    vector<S>b(n);
    rep(i,0,n) b[i].now = a[i];
    lazy_segtree<S,op,e,F,mp,comp,id> seg(b);

    vector<mint> inv(300000);
    rep(i,1,300000){
        inv[i] = 1;
        inv[i] /= i;
    }

    rep(i,0,m){
        ll l,r,x;
        cin>>l>>r>>x;
        l--;
        ll dif = r-l;
        mint a = (dif-1) * inv[dif];
        mint b = x * inv[dif];
        seg.apply(l,r,F(a,b));
    }
    rep(i,0,n){
        mint ans = seg.get(i).now;
        cout << ans.val() << endl;
    }
    return 0;
}