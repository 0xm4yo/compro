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

int main()
{
    ll n,m,t;
    cin>>n>>m>>t;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    vector<vector<pair<ll,ll>>> to(n), ba(n);
    rep(i,0,m){
        ll u,v,c;
        cin>>u>>v>>c;
        u--;v--;
        to[u].push_back({v,c});
        ba[v].push_back({u,c});
    }

    priority_queue_rev<pair<ll,ll>> hq;
    vector<ll> bd(n,INF);
    hq.push({0,0});
    while(!hq.empty()){
        auto [d,now] = hq.top(); hq.pop();
        if (bd[now]!=INF) continue;
        bd[now] = d;
        for (auto [pre,c]: ba[now]){
            if (bd[pre]!=INF) continue;
            hq.push({d+c,pre});
        }
    }

    vector<ll> td(n,INF);
    hq.push({0,0});
    while(!hq.empty()){
        auto [d,now] = hq.top(); hq.pop();
        if (td[now]!=INF) continue;
        td[now] = d;
        for (auto [nex,c]: to[now]){
            if (td[nex]!=INF) continue;
            hq.push({d+c,nex});
        }
    }
    ll ans = 0;
    rep(i,0,n){
        ll rem = t-td[i]-bd[i];
        if (rem<0) continue;
        chmax(ans, rem*a[i]);
    }
    cout << ans << endl;
    
    // cout << fixed << setprecision(18);
    return 0;
}