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

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);

    ll n,m;
    cin>>n>>m;
    vector<ll>x(n);
    vector<ll>y(n);
    rep(i,0,n)cin>>x[i];
    rep(i,0,n)cin>>y[i];
    vector<ll> a(m),b(m),z(m);

    rep(i,0,m)cin>>a[i]>>b[i]>>z[i];
    rep(i,0,m)a[i]--;
    rep(i,0,m)b[i]--;
    vector<tuple<ll,ll,ll,ll>> tp;
    rep(i,0,n)tp.push_back({x[i],0,i,n});
    rep(i,0,n)tp.push_back({y[i],1,i,n+1});
    rep(i,0,m)tp.push_back({z[i],2,a[i],b[i]});
    sort(all(tp));

    ll ans = INF;
    dsu uf0(n+2);
    ll cost0 = 0;
    for(auto [cost, mode, st, ed]: tp){
        if (uf0.same(st,ed)) continue;
        if (mode==0) continue;
        if (mode==1) continue;
        uf0.merge(st,ed);
        cost0 += cost;
    }
    if (uf0.groups().size()==3) chmin(ans, cost0);

    dsu uf1(n+2);
    ll cost1 = 0;
    for(auto [cost, mode, st, ed]: tp){
        if (uf1.same(st,ed)) continue;
        if (mode==1) continue;
        uf1.merge(st,ed);
        cost1 += cost;
    }
    if (uf1.groups().size()==2) chmin(ans, cost1);

    dsu uf2(n+2);
    ll cost2 = 0;
    for(auto [cost, mode, st, ed]: tp){
        if (uf2.same(st,ed)) continue;
        if (mode==0) continue;
        uf2.merge(st,ed);
        cost2 += cost;
    }
    if (uf2.groups().size()==2) chmin(ans, cost2);

    dsu uf3(n+2);
    ll cost3 = 0;
    for(auto [cost, mode, st, ed]: tp){
        if (uf3.same(st,ed)) continue;
        uf3.merge(st,ed);
        cost3 += cost;
    }
    if (uf3.groups().size()==1) chmin(ans, cost3);
    if (ans==INF) ans = -1;
    cout << ans << endl;
    return 0;
}