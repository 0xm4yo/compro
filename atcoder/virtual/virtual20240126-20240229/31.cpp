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
const double INF = 1e18+10;
ll coordinate(ll h, ll w, ll W){ return h*W + w; } // 二次元座標を一次元座標に変換

#define endl "\n" // インタラクティブの時はコメントアウトする

double op(double a, double b) { return min(a, b); }
double e(){ return INF; }

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(18);
    
    ll n,k;
    cin>>n>>k;
    ll sx, sy;
    cin>>sx>>sy;
    vector<ll> x(n+1), y(n+1);
    rep(i,1,n+1) cin>>x[i]>>y[i];
    x[0] = sx;
    y[0] = sy;
    vector<double> dp(n+1,INF);
    dp[0] = 0.0;
    segtree<double,op,e> seg(dp);

    auto f = [&](ll a,ll b){
        ll res = (x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]);
        return (double)sqrt(res);
    };

    double tot = 0.0;
    rep(i,1,n+1){
        tot += f(i-1,i);
        ll l = max(i-k, 0LL);
        double _min = seg.prod(l, i);
        if (i+1<=n) dp[i] = _min - f(i,i+1) + f(0,i) + f(0,i+1);
        else dp[i] = _min + f(0,i);
        seg.set(i, dp[i]);
    }
    cout << tot + dp[n] << endl;    
    

    return 0;
}