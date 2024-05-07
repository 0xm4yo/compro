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

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);

    ll n,m;
    cin>>n>>m;
    vector<bool> mitei(n);
    vector<ll> sd(n), gd(n);
    vector<vector<ll>> g(n);
    rep(i,0,m){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        if (u==-1){
            mitei[v] = true;
        }else{
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    
    queue<ll> q;
    q.push(0);
    vector<ll> v0(n,INF);
    v0[0] = 0;
    while(!q.empty()){
        ll now = q.front(); q.pop();
        for (auto nex: g[now]){
            if (v0[nex]!=INF) continue;
            q.push(nex);
            v0[nex] = v0[now] + 1;
        }
    }

    q.push(n-1);
    vector<ll> vn(n,INF);
    vn[n-1] = 0;
    while(!q.empty()){
        ll now = q.front(); q.pop();
        for (auto nex: g[now]){
            if (vn[nex]!=INF) continue;
            q.push(nex);
            vn[nex] = vn[now] + 1;
        }
    }

    ll w0 = INF;
    ll wn = INF;
    rep(i,0,n){
        if (mitei[i]){
            chmin(w0, v0[i]);
            chmin(wn, vn[i]);
        }
    }

    rep(i,0,n){
        ll ans = INF;
        chmin(ans, v0[n-1]);
        chmin(ans, w0 + wn + 2);
        chmin(ans, v0[i] + wn + 1);
        chmin(ans, w0 + vn[i] + 1);
        if (ans==INF) cout << -1 << endl;
        else cout << ans << endl;
    }
    
    return 0;
}