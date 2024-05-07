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

struct S
{
    ll cnt0, cnt1;
    S(): cnt0(0), cnt1(0) {}
    S(ll size){
        cnt0 = size;
        cnt1 = 0;
    }
};

using F = bool;

S op(S a, S b){
    S res;
    res.cnt0 = a.cnt0 + b.cnt0;
    res.cnt1 = a.cnt1 + b.cnt1;
    return res;
}

S e(){ return S(); }
S mapping(F f, S x){
     if (f){
        swap(x.cnt0, x.cnt1);
     }
     return x;
}
F composition(F f, F g){ return f^g; }
F id(){ return false; }

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
    ll q;
    cin>>q;
    map<ll,vector<tuple<ll,ll,ll>>> mp;
    CC<ll> cc;
    rep(i,0,q){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll x = min(a,c);
        ll y = min(b,d);
        cc.add(x);
        cc.add(x+abs(a-c));
        mp[y].push_back({x,x+abs(a-c),1});
        mp[y+abs(b-d)].push_back({x,x+abs(a-c),1});
    }
    cc.init();
    vector<S> v(cc.size());
    rep(i,0,cc.size()){
        if (i+1==cc.size()){
            v[i] = S(1);
        }else{
            ll dif = cc[i+1]-cc[i];
            v[i] = S(dif);
        }
    }
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

    auto itr = mp.begin();
    ll ans = 0;
    ll prey = 0;
    while(itr!=mp.end()){
        auto &[key, arr] = *itr;
        ll dif = key - prey;
        ans += seg.all_prod().cnt1*dif;
        for (auto [l,r,c]: arr){
            seg.apply(cc(l),cc(r),F(true));
        }
        prey = key;
        itr++;
    }
    cout << ans << endl;
}