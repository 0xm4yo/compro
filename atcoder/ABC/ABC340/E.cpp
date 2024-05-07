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
const long long INF = (ll)1e18+10;
ll coordinate(ll h, ll w, ll W){ return h*W + w; } // 二次元座標を一次元座標に変換

struct S{
    long long value;
    int size;
};
using F = long long;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){ return {x.value + f*x.size, x.size}; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n), b(m);
    rep(i,0,n)cin>>a[i];
    rep(i,0,m)cin>>b[i];

    std::vector<S> v(n, {0, 1});
    rep(i,0,n) v[i].value = a[i];
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

    
    rep(i,0,m){
        ll cnt = seg.get(b[i]).value;
        seg.apply(b[i], -cnt);
        if (cnt==0) continue;
        ll cir = cnt/n;
        ll rem = cnt%n;
        ll c = 1;
        seg.apply(0, n, cir);
        ll st = (b[i]+c)%n;
        if (st+rem>n){
            seg.apply(st, n, 1);
            ll nokori = rem - (n-st);
            seg.apply(0, nokori, 1);
        }else{
            seg.apply(st,st+rem, 1);
        }
        
    }
    rep(i,0,n) cout << seg.get(i).value << endl;


    
    // cout << fixed << setprecision(18);
    return 0;
}