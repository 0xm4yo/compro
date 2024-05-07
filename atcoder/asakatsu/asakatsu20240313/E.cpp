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
    bool isgood;
    ll l0, r0;
    S(){
        isgood = true;
        l0 = -1;
        r0 = -1;
    }
    S(ll x){
        isgood = true;
        l0 = x^1;
        r0 = x^1;
    }
};

S op(S l, S r){
    S res;
    res.l0 = l.l0;
    res.r0 = r.r0;
    res.isgood = false;
    if ((l.r0!=r.l0) && (l.isgood&r.isgood)){
        res.isgood = true;
    }
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
        if (x.l0!=-1) x.l0 ^= 1;
        if (x.r0!=-1) x.r0 ^= 1;
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
    vector<S>a(n);
    rep(i,0,n)a[i]=S(s[i]-'0');

    lazy_segtree<S,op,e,F,mp,comp,id> seg(a);

    // ll m0 = seg.prod(0,2).isgood;

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
            YesNo(seg.prod(l,r).isgood);
        }
    }

    return 0;
}