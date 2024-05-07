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
    vector<ll>x(n),y(n);
    rep(i,0,n)cin>>x[i];
    rep(i,0,n)cin>>y[i];
    vector<ll>a(m),b(m),z(m);
    rep(i,0,m){
        cin>>a[i]>>b[i]>>z[i];
        a[i]--;b[i]--;
    }
    vector<tuple<ll,ll,ll,ll>> tp;
    rep(i,0,n) tp.push_back({x[i],0,i,n});
    rep(i,0,n) tp.push_back({y[i],1,i,n+1});
    rep(i,0,m) tp.push_back({z[i],2,a[i],b[i]});

    sort(all(tp));
    // only road
    dsu uf(n+2);
    ll tot = 0;
    for (auto [cost,type,u,v]: tp){
        if (type!=2) continue;
        if (uf.same(u,v)) continue;
        tot += cost;
        uf.merge(u,v);
    }
    ll ans = INF;
    if (uf.groups().size()==3) chmin(ans, tot);
    
    // air + road
    dsu uf1(n+2);
    tot = 0;
    for (auto [cost,type,u,v]: tp){
        if (type==1) continue;
        if (uf1.same(u,v)) continue;
        tot += cost;
        uf1.merge(u,v);
    }
    chmin(ans, tot);

    // port + road
    dsu uf2(n+2);
    tot = 0;
    for (auto [cost,type,u,v]: tp){
        if (type==0) continue;
        if (uf2.same(u,v)) continue;
        tot += cost;
        uf2.merge(u,v);
    }
    chmin(ans, tot);

    // all
    dsu uf3(n+2);
    tot = 0;
    for (auto [cost,type,u,v]: tp){
        if (uf3.same(u,v)) continue;
        tot += cost;
        uf3.merge(u,v);
    }
    chmin(ans, tot);

    cout << ans << endl;

    
    return 0;
}