#include <bits/stdc++.h>
#include <atcoder/all>
// #include <boost/multiprecision/cpp_int.hpp>

// namespace mp = boost::multiprecision;
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
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll>v(n);
    rep(i,0,n)cin>>v[i];
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,-INF));
    dp[0][0] = 0;
    vector<vector<ll>> cnt(n+1,vector<ll>(n+1,0));
    cnt[0][0] = 1;
    rep(i,0,n)rep(j,0,n){
        if (dp[i][j]==-INF) continue;
        if (dp[i+1][j]<dp[i][j]){
            chmax(dp[i+1][j],dp[i][j]);
            cnt[i+1][j] = cnt[i][j];
        }else if (dp[i+1][j]==dp[i][j]){
            cnt[i+1][j] += cnt[i][j];
        }
        if (dp[i+1][j+1]<dp[i][j]+v[i]){
            chmax(dp[i+1][j+1], dp[i][j] + v[i]);
            cnt[i+1][j+1] = cnt[i][j];
        }else if (dp[i+1][j+1]==dp[i][j]+v[i]){
            cnt[i+1][j+1] += cnt[i][j];
        }
    }
    double ans = 0.0;
    ll par=1,ch=0;
    rep(i,a,b+1){
        if (ans<(double)dp[n][i]/(double)i){
            chmax(ans, (double)dp[n][i]/(double)i);
            par=i;
            ch=dp[n][i];
        }
    }
    ll tot = 0;
    
    rep(i,a,b+1){
        ll g = lcm(par,i);
        if (ch*(g/par) == dp[n][i]*(g/i)) tot += cnt[n][i];
    }

    cout << fixed << setprecision(18);
    cout << ans << endl;
    cout << tot << endl;
    return 0;
}