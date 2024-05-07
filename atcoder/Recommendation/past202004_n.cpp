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
// const long long INF = 4004004003104004004LL; // (int)INF = 1010931620;
ll coordinate(ll h, ll w, ll W){ return h*W + w; } // 二次元座標を一次元座標に変換

#define endl "\n" // インタラクティブの時はコメントアウトする

using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b){ return std::min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

// Coodinate Compression
// https://youtu.be/fR3W5IcBGLQ?t=8550
template<typename T=ll>
struct CC {
    bool initialized;
    vector<T> xs;
    CC(): initialized(false) {}
    void add(T x) { xs.push_back(x);}
    void init() {
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(),xs.end()),xs.end());
        initialized = true;
    }
    int operator()(T x) {
        if (!initialized) init();
        // lower_bound に修正
        return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    }
    T operator[](ll i) {
        if (!initialized) init();
        return xs[i];
    }
    ll size() {
        if (!initialized) init();
        return xs.size();
    }
};

int main(){
    ll n,q;
    cin>>n>>q;

    vector<S> v(2002000);
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

    vector<tuple<ll,ll,ll,ll>> arr;
    CC<ll> cc;
    rep(i,0,n){
        ll x,y,d,c;
        cin>>x>>y>>d>>c;
        cc.add(x);
        cc.add(x+d+1);
        arr.push_back({y,d,x,c});
        arr.push_back({y+d+1,d,x,-c});
    }
    rep(i,0,q){
        ll a,b;
        cin>>a>>b;
        cc.add(a);
        arr.push_back({b,INF,a,i});
    }
    vector<ll> ans(q);
    sort(all(arr));
    cc.init();

    for (auto [b,d,a,c]: arr){
        if (d==INF){
            ll idx = cc(a);
            ans[c] = seg.get(idx);
        }else{
            ll x = a;
            ll l = cc(x);
            ll r = cc(x+d+1);
            seg.apply(l,r,c);
        }
    }
    rep(i,0,q) cout << ans[i] << endl;
}
