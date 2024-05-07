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

// Verify: https://atcoder.jp/contests/abc322/tasks/abc322_f
struct S
{
    ll l0, l1;
    ll cnt0, cnt1;
    S(){
        l0 = l1 = 0;
        cnt0 = cnt1 = 0;
    }
    S(ll x){
        l0 = 0;
        l1 = 0;
        cnt0 = 1^x;
        cnt1 = x;
    }
};

S op(S l, S r){
    S res;
    res.l0 = l.cnt0*r.cnt1 + l.l0 + r.l0;
    res.l1 = l.cnt1*r.cnt0 + l.l1 + r.l1;
    res.cnt0 = l.cnt0 + r.cnt0;
    res.cnt1 = l.cnt1 + r.cnt1;
    return res;
}

S e(){
    return S();
}

struct F
{
    bool flag;
    F(): flag(false) {}
    F(bool x): flag(x) {}
};

S mp(F f, S x){
    if (f.flag){
        swap(x.l0, x.l1);
        swap(x.cnt0, x.cnt1);
    }
    return x;
}

F comp(F f, F g){
    f.flag ^= g.flag;
    return f;
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
        a[i] = S(aa);
    }

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
            cout << seg.prod(l,r).l1 << endl;
        }
    }

    return 0;
}