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
    vector<ll> a(m),b(m),x(m),y(m);
    rep(i,0,m)cin>>a[i]>>b[i]>>x[i]>>y[i];
    vector<vector<pair<ll,ll>>> g(n);
    rep(i,0,m){
        a[i]--;
        b[i]--;
    }
    rep(i,0,m){
        g[a[i]].emplace_back(b[i],i);
        g[b[i]].emplace_back(a[i],i);
    }
    vector<pair<ll,ll>> ans(n, {INF,INF});
    queue<ll> q;
    q.push(0);
    ans[0].first = 0;
    ans[0].second = 0;
    while(!q.empty()){
        ll now = q.front(); q.pop();
        for (auto [nex, idx]: g[now]){
            if (ans[nex].first!=INF) continue;
            if (a[idx]==now){
                ans[nex].first = ans[now].first + x[idx];
                ans[nex].second = ans[now].second + y[idx];
            }else{
                ans[nex].first = ans[now].first - x[idx];
                ans[nex].second = ans[now].second - y[idx];
            }
            q.push(nex);
        }
    }

    rep(i,0,n){
        if (ans[i].first==INF){
            cout << "undecidable" << endl;
        }else{
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }


    
    return 0;
}