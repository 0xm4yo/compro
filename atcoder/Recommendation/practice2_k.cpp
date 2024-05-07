#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
template <class T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define smod(n, m) ((((n) % (m)) + (m)) % (m)) // 非負mod
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

inline int popcount(int n) { return __builtin_popcount(n); } // 2進数で表した場合に立ってるビット数がいくつか
inline int popcount(ll n) { return __builtin_popcountll(n); }
inline int ctz(int n) { return n != 0 ? __builtin_ctz(n) : -1; } // 2進数で表した場合に 1 の位からいくつ 0 が連なっているか
inline int ctz(ll n) { return n != 0 ? __builtin_ctzll(n) : -1; }
inline int clz(int n) { return n != 0 ? (31 - __builtin_clz(n)) : -1; } // 2進数で表した場合に左側にいくつ 0 を埋める必要があるか
inline int clz(ll n) { return n != 0 ? (63 - __builtin_clzll(n)) : -1; }

const double PI = 3.141592653589793;
const vector<int> DX = { 1, 0, -1, 0 };
const vector<int> DY = { 0, 1, 0, -1 };
const long long INF = 4004004003104004004LL; // (int)INF = 1010931620;
ll coordinate(ll h, ll w, ll W){ return h*W + w; } // 二次元座標を一次元座標に変換

#define endl "\n" // インタラクティブの時はコメントアウトする

using mint = modint998244353;
struct S
{
    mint x;
    ll sz;
    S(): x(0), sz(0) {}
    S(mint x, ll sz): x(x), sz(sz) {}
};

S op(S l, S r){
    S res;
    res.x = l.x + r.x;
    res.sz = l.sz + r.sz;
    return res;
}

S e(){
    return S();
}

struct F
{
    mint b,c;
    F(): b((mint)1), c((mint)0) {}
    F(mint bb, mint cc): b(bb), c(cc) {}
};

S mp(F f, S x){
    x.x *= f.b;
    x.x += f.c*x.sz;
    return x;
}

F comp(F f, F g){
    return F(f.b*g.b, g.c*f.b+f.c);
}

F id(){
    return F();
}

int main()
{
    ll n,q;
    cin>>n>>q;
    vector<S>a(n);
    rep(i,0,n){
        ll aa;
        cin>>aa;
        a[i] = S(aa, 1);
    }
    lazy_segtree<S,op,e,F,mp,comp,id> seg(a);
    while (q){
        q--;
        ll type;
        cin>>type;
        ll l,r;
        cin>>l>>r;
        if (type==0){
            ll b,c;
            cin>>b>>c;
            seg.apply(l,r,F((mint)b,(mint)c));
        }else{
            cout << seg.prod(l,r).x.val() << endl;
        }
    }

    return 0;
}