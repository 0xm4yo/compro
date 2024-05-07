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

// #define endl "\n" // インタラクティブの時はコメントアウトする

ll dp[2000][2][2];

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);
    
    ll n;
    cin>>n;
    vector<ll>p(n),q(n),qpos(n);
    rep(i,0,n)cin>>p[i];
    rep(i,0,n)cin>>q[i];
    rep(i,0,n)p[i]--;
    rep(i,0,n)q[i]--;

    rep(i,0,n) qpos[q[i]] = i;

    vector<int> left(n,-1),right(n,-1);
    // p: [l, r], q: [L, R]
    function<bool(ll,ll,ll,ll)> dfs = [&](ll l, ll r, ll L, ll R){
        ll now = p[l];
        ll pos = qpos[now];
        if (pos < L || R < pos) return false;
        // L <= pos <= R
        if (L != pos){
            left[now] = p[l+1];
            if (!dfs(l+1, l+pos-L, L, pos-1)) return false;
        }
        if (pos != R){
            right[now] = p[l+pos-L+1];
            if (!dfs(l+pos-L+1, r, pos+1, R)) return false;
        }
        return true;
    };

    if (p[0] != 0){
        cout << -1 << endl;
        return 0;
    }

    if (!dfs(0,n-1,0,n-1)){
        cout << -1 << endl;
        return 0;
    }

    rep(i,0,n){
        cout << left[i]+1 << " " << right[i]+1 << endl;
    }

    return 0;
}