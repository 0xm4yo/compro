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

using P = pair<ll,ll>;
vector<ll> dijkstra(vector<vector<P>> &graph, ll st = 0){
    // graph: 重み付き連結リスト
    ll sz = graph.size();
    vector<ll> v(sz, INF);
    priority_queue_rev<P> hq;
    hq.push(make_pair(0, st));
    while(!hq.empty()){
        auto [d, now] = hq.top(); hq.pop();
        if (v[now]!=INF) continue;
        v[now] = d;
        for (auto [nex, cost]: graph[now]){
            if (v[nex]!=INF) continue;
            hq.push(make_pair(d+cost, nex));
        }
    }
    return v;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);

    ll n,m;
    cin>>n>>m;

    vector<vector<pair<ll,ll>>> g(n);

    rep(i,0,m){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back({b,1});
        g[b].push_back({a,1});
    }


    auto v = dijkstra(g, 0);
    if (v[n-1]!=2){
        cout << "IMPOSSIBLE" << endl;
    }else{
        cout << "POSSIBLE" << endl;
    }
    
    return 0;
}