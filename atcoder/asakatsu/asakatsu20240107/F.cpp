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

struct S
{
    bool all0, all1;
    ll len;
    ll l0, r0, mx0;
    ll l1, r1, mx1;
    S(){
        all0 = true; all1 = true;
        len = 0;
        l0 = 0; r0 = 0; mx0 = 0;
        l1 = 0; r1 = 0; mx1 = 0;
    }
    S(ll x){
        all0 = (x==0); all1 = (x==1);
        len = 1; 
        l0 = x^1; r0 = x^1; mx0 = x^1;
        l1 = x; r1 = x; mx1 = x;        
    }
};

S op(S l, S r){
    S res;
    res.all0 = l.all0 & r.all0;
    res.all1 = l.all1 & r.all1;
    res.l0 = l.l0;
    if (l.all0) res.l0 += r.l0;
    res.r0 = r.r0;
    if (r.all0) res.r0 += l.r0;
    res.l1 = l.l1;
    if (l.all1) res.l1 += r.l1;
    res.r1 = r.r1;
    if (r.all1) res.r1 += l.r1;
    res.mx0 = max({l.mx0, r.mx0, l.r0 + r.l0});
    res.mx1 = max({l.mx1, r.mx1, l.r1 + r.l1});
    return res;
}

S e(){
    return S();
}

struct F
{
    bool flag;
    F(bool x){ flag = x; }
};

S mp(F f, S x){
    if (f.flag){
        swap(x.all0, x.all1);
        swap(x.l0, x.l1);
        swap(x.r0, x.r1);
        swap(x.mx0, x.mx1);
    }
    return x;
}

F comp(F f, F g){
    f.flag ^= g.flag;
    return f;
}

F id(){
    return F(false);
}

int main()
{
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<S> a(n);
    rep(i,0,n) a[i] = S(s[i]-'0');

    lazy_segtree<S,op,e,F,mp,comp,id> seg(a);
    while (q){
        q--;
        ll c;
        cin>>c;
        ll l,r;
        cin>>l>>r;
        l--;
        if (c==1){
            seg.apply(l,r,F(true));
        }else{
            cout << seg.prod(l,r).mx1 << endl;
        }
    }

    return 0;
}