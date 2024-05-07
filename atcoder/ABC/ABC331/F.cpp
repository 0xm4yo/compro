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

mint op(mint a, mint b){ return a+b; }
mint e(){ return 0; }

int main()
{
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    ll b = 97;
    vector<mint> powb = {1};
    rep(i,0,n+10) powb.push_back((mint)powb.back()*(mint)b);
    segtree<mint,op,e> seg1(n), seg2(n);
    rep(i,0,n){
        seg1.set(i, powb[i]*(s[i]-'a'+10));
    }
    rrep(i,n-1,0){
        seg2.set(i, powb[n-1-i]*(s[i]-'a'+10));
    }
    while(q){
        q--;
        ll c;
        cin>>c;
        if (c==1){
            ll x;
            char y;
            cin>>x>>y;
            x--;
            seg1.set(x, powb[x]*(y-'a'+10));
            seg2.set(x, powb[n-1-x]*(y-'a'+10));
        }else{
            ll l,r;
            cin>>l>>r;
            l--;
            mint aa = seg1.prod(l,r);
            mint bb = seg2.prod(l,r);
            aa /= powb[l];
            bb /= powb[n-r];
            YesNo(aa==bb);
        }
    }
    return 0;
}