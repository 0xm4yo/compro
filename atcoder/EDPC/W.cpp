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

struct S{
    ll x;
    S(){ x = 0; }
    S(ll y) { x = y; }
};

S op(S l, S r){
    S res;
    res.x = max(l.x, r.x);
    return res;
}
S e(){ return S(); }

struct F{
    ll x;
    F(){ x = 0; }
    F(ll y){ x = y; }
};

S mp(F f, S m){
    m.x += f.x;
    return m;
}

F comp(F f, F g){
    g.x += f.x;
    return g;
}

F id(){ return F(); }

int main()
{
    ll n,m;
    cin>>n>>m;

    vector<tuple<ll,ll,ll>> rl;
    rep(i,0,m){
        ll l,r,a;
        cin>>l>>r>>a;
        l--;
        rl.push_back({r,l,a});
    }
    sort(all(rl));
    vector<S> dp(n+1);
    lazy_segtree<S,op,e,F,mp,comp,id> seg(dp);

    ll pos = 0;
    rep(i,1,n+1){
        while(1){
            auto [r,l,a] = rl[pos];
            if (r==i){
                seg.apply(l,r,F(a));
                pos++;
            }else{
                break;
            }
        }
        ll mx = seg.prod(0,i).x;
        seg.set(i,S(mx));
    }

    cout << seg.all_prod().x << endl;   


    return 0;
}