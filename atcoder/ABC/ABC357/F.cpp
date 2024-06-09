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

// Verify: https://atcoder.jp/contests/abc322/tasks/abc322_f
struct S
{
    mint a, b, ab;
    mint sz;
    S(){
        a = 0;
        b = 0;
        ab = 0;
        sz = 0;
    }
    S(ll x, ll y){
        a = x;
        b = y;
        ab = x*y;
        sz = 1;
    }
};

S op(S l, S r){
    S res;
    res.a = l.a + r.a;
    res.b = l.b + r.b;
    res.ab = l.ab + r.ab;
    res.sz = l.sz + r.sz;
    return res;
}

S e(){
    return S();
}

struct F
{
    mint x;
    mint y;
    F(){
        x = 0;
        y = 0;
    }
    F(ll a, ll b){
        x = a;
        y = b;
    }
};

S mp(F f, S x){
    x.ab += x.a * f.y + x.b * f.x + x.sz * f.x * f.y;
    x.a += x.sz * f.x;
    x.b += x.sz * f.y;
    return x;
}

F comp(F f, F g){
    f.x += g.x;
    f.y += g.y;
    return f;
}

F id(){
    return F();
}



int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);

    ll n,q;
    cin>>n>>q;
    vector<ll> a(n),b(n);
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)cin>>b[i];   
    
    vector<S> arr(n);
    rep(i,0,n) arr[i]=S(a[i], b[i]);

    lazy_segtree<S,op,e,F,mp,comp,id> seg(arr);
    while (q){
        q--;
        ll c;
        cin>>c;
        ll l,r;
        cin>>l>>r;
        l--;
        if (c==1){
            ll x;
            cin>>x;
            seg.apply(l,r,F(x,0));
        }else if(c==2){
            ll x;
            cin>>x;
            seg.apply(l,r,F(0,x));
        }else{
            cout << seg.prod(l,r).ab.val() << endl;
        }
    }

    return 0;
}