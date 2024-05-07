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
    vector<vector<ll>> a(6,vector<ll>(6));
    rep(i,1,5)rep(j,1,5)cin>>a[i][j];
    ll ans = 0;
    rep(s,1,1LL<<16){
        vector<vector<ll>> g(6,vector<ll>(6));
        rep(i,0,16){
            if (s&(1LL<<i)){
                ll h = (i/4) + 1;
                ll w = (i%4) + 1;
                g[h][w] = 1;
            }
        }
        bool flag = true;
        rep(i,1,5)rep(j,1,5){
            if (a[i][j] && !g[i][j]) flag = false;
        }
        if (!flag) continue;
        dsu uf(36);
        rep(i,0,6)rep(j,0,6){
            rep(k,0,4){
                ll nh = i + DX[k];
                ll nw = j + DY[k];
                if (nh<0 || nh>=6 || nw<0 || nw>=6) continue;
                if (g[nh][nw]==g[i][j]) uf.merge(coordinate(i,j,6),coordinate(nh,nw,6));
            }
        }
        if (uf.groups().size()>2) continue;
        ans++;
    }
    cout << ans << endl;

    
    // cout << fixed << setprecision(18);
    return 0;
}