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

#define endl "\n" // インタラクティブの時はコメントアウトする

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
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);
    
    ll n,m,q;
    cin>>n>>m>>q;

    vector<S> v(m+1, {0, 1});
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

    vector<ll> c(q),l(q),r(q),x(q),h(q),w(q);
    rep(i,0,q){
        cin>>c[i];
        if (c[i]==1){
            cin>>l[i]>>r[i]>>x[i];
        }else if(c[i]==2){
            cin>>h[i]>>x[i];
        }else{
            cin>>h[i]>>w[i];
        }
    }

    vector<ll> last(n+1,-1);
    vector<vector<ll>> g(q);
    rep(i,0,q){
        if(c[i]==2){
            last[h[i]] = i;
        }
        if(c[i]==3){
            if (last[h[i]]!=-1){
                g[last[h[i]]].push_back(w[i]);
            }
        }
    }
    
    map<pair<ll,ll>, ll> mp;
    rep(i,0,n+1) last[i] = -1;
    rep(i,0,q){
        if (c[i]==1){
            seg.apply(l[i], r[i]+1, x[i]);
        }else if(c[i]==2){
            last[h[i]] = i;
            for (auto ww: g[i]){
                mp[{i,ww}] = seg.get(ww).value;
            }
        }else{
            if (last[h[i]]==-1){
                cout << seg.get(w[i]).value << endl;
            }else{
                ll ans = x[last[h[i]]];
                ans += seg.get(w[i]).value;
                ans -= mp[{last[h[i]], w[i]}];
                cout << ans << endl;
            }
        }
    }

    return 0;
}