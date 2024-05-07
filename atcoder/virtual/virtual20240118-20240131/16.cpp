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

ll op(ll a, ll b){ return min(a,b); }
ll e(){ return INF; }

int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,0,n)cin>>a[i];
    auto b = a;
    sort(all(b));
    map<ll,ll> mp;
    rep(i,0,n)mp[a[i]]++;
    rep(i,0,n){
        ll idx = lower_bound(all(b), a[i]) - b.begin();
        ll pos = idx + mp[a[i]] - 1;
        mp[a[i]]--;
        a[i] = pos;
    }

    segtree<ll,op,e> seg(n+1);
    rep(i,0,n) seg.set(a[i],i);
    
    vector<bool> v(n);
    ll ans = 0;
    rep(i,0,n){
        if (v[i]) continue;
        ans++;
        ll now = i;
        while(1){
            v[now] = true;
            seg.set(a[now],INF);
            ll nex = seg.prod(a[now]+1,n);
            if (nex==INF) break;
            if (nex<now) break;
            now = nex;
        }
    }
    cout << ans << endl;
    
    // cout << fixed << setprecision(18);
    return 0;
}