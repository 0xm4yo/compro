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
vector<vector<mint>> keta(10, vector<mint>(200200));

struct S
{
    mint x;
    ll kmin, kmax;
    S(): x(0), kmin(0), kmax(0) {}
    S(ll num, ll b, ll c){
        kmin = b;
        kmax = c;
        x = keta[num][kmax] - keta[num][kmin];
    }
};

using F = ll;

S op(S a, S b){
    S res;
    res.x = a.x + b.x;
    res.kmax = max(a.kmax, b.kmax);
    res.kmin = min(a.kmin, b.kmin);
    return res;
}
S e(){ return S(); }

S mapping(F f, S x){ 
    if (f) x.x = keta[f][x.kmax] - keta[f][x.kmin];
    return x; 
}
F composition(F f, F g){ 
    if (f) return f; 
    else return g;
}
F id(){ return 0LL; }

int main(){
    ll n,q;
    cin>>n>>q;
    vector<S> v(n);
    rep(i,1,10){
        rep(j,1,n+1){
            keta[i][j] = keta[i][j-1]*(mint)10 + (mint)i;
        }
    }

    rep(i,0,n){
        v[i] = S(1, n-i-1, n-i);
    }

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

    rep(i,0,q){
        ll l,r,d;
        cin>>l>>r>>d;
        l--;
        seg.apply(l,r,d);
        cout << seg.all_prod().x.val() << endl;
    }
}