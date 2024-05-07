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

using mint = modint998244353;

int main()
{
    ll n,m;
    cin>>n>>m;

    vector<vector<ll>> g(n);
    vector<ll> indeg(n);
    rep(i,0,m){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
        indeg[u]++;
        indeg[v]++;
    }

    queue<ll> q;
    vector<bool> vv(n);
    rep(i,0,n) if(indeg[i]==1) q.push(i);
    while(!q.empty()){
        ll now = q.front(); q.pop();
        vv[now] = true;
        for (auto nex: g[now]){
            if (vv[nex]) continue;
            indeg[nex]--;
            if (indeg[nex]==1) q.push(nex);
        }
    }
    
    rep(i,0,n){
        if (indeg[i]==0 || indeg[i]>2){
            cout << 0 << endl;
            return 0;
        }
    }

    mint ans = 1;
    vector<bool>v(n);
    rep(i,0,n){
        if(indeg[i]!=2) continue;
        if (v[i]) continue;
        q.push(i);
        ans *= 2;
        while(!q.empty()){
            ll now = q.front(); q.pop();
            for (auto nex: g[now]){
                if (v[nex]) continue;
                v[nex] = true;
                q.push(nex);
            }
        }
    }


    cout << ans.val() << endl;


    // cout << fixed << setprecision(18);
    return 0;
}