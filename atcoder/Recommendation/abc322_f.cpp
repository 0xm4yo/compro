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
    bool all0,all1;
    ll l0,r0,l1,r1;
    ll mx0,mx1;
    S(){
        all0 = all1 = true;
        l0 = r0 = l1 = r1 = 0;
        mx0 = mx1 = 0;
    }
    S(ll x){
        all0 = (0==x);
        all1 = (1==x);
        l0 = r0 = x^1;
        l1 = r1 = x;
        mx0 = x^1;
        mx1 = x;
    }
};

S op(S l, S r){
    S res;
    res.all0 = l.all0 & r.all0;
    res.all1 = l.all1 & r.all1;
    res.l0 = l.l0 + (l.all0 ? 1LL : 0LL)*r.l0;
    res.l1 = l.l1 + (l.all1 ? 1LL : 0LL)*r.l1;
    res.r0 = r.r0 + (r.all0 ? 1LL : 0LL)*l.r0;
    res.r1 = r.r1 + (r.all1 ? 1LL : 0LL)*l.r1;
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
    F(): flag(false) {}
    F(bool x): flag(x) {}
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
    return F();
}

int main()
{
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<S> a(n);
    rep(i,0,n){
        a[i] = S(s[i]-'0');
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
            cout << seg.prod(l,r).mx1 << endl;
        }
    }

    return 0;
}
