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
// const long long INF = (ll)1e18+10;
ll coordinate(ll h, ll w, ll W){ return h*W + w; } // 二次元座標を一次元座標に変換

using S = long long;
using F = long long;

const S INF = 8e18;
const F ID = 8e18;

S op(S a, S b){ return a; }
S e(){ return INF; }
S mapping(F f, S x){ return (f < x ? f : x); }
F composition(F f, F g){ return (g > f ? f : g); }
F id(){ return ID; }


int main()
{
    ll n,q;
    cin>>n>>q;
    vector<ll>s(n),t(n),x(n);
    rep(i,0,n)cin>>s[i]>>t[i]>>x[i];
    vector<tuple<ll,ll,ll>> tp;
    rep(i,0,n)tp.push_back({x[i],s[i],t[i]});
    sort(all(tp));

    vector<ll> arr(q);
    rep(i,0,q)cin>>arr[i];

    std::vector<S> v(q,INF);
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

    for (auto[xx,ss,tt]: tp){
        ll l = ss-xx;
        ll r = tt-xx;
        ll il = lower_bound(all(arr), l) - arr.begin();
        ll ir = lower_bound(all(arr), r) - arr.begin();
        chmax(il,0LL);
        chmin(ir,q);
        seg.apply(il,ir,xx);
    }
    rep(i,0,q){
        if (seg.get(i)==INF) cout << -1 << endl;
        else cout << seg.get(i) << endl;
    }
    // cout << fixed << setprecision(18);
    return 0;
}