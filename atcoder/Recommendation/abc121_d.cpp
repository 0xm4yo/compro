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

    ll a,b;
    cin>>a>>b;

    ll SIZE = 60;
    auto f = [&](ll x){
        ll n = SIZE;
        vector<ll>res(n+1);
        rep(s,1,n+1){
            vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(2, vector<ll>(2)));
            dp[0][0][1] = 1;
            rep(i,0,n){
                ll now = (x>>(n-i-1)) & 1;
                rep(j,0,2)rep(mode,0,2){
                    if (dp[i][j][mode]==0) continue;
                    if (mode){
                        rep(bit,0,2){
                            if (bit<now){
                                if (i+1==s){
                                    if (bit) dp[i+1][bit][0] += dp[i][j][mode];
                                }else{
                                    dp[i+1][bit][0] += dp[i][j][mode];
                                }
                            }else if(bit==now){
                                if (i+1==s){
                                    if (bit) dp[i+1][bit][1] += dp[i][j][mode];
                                }else{
                                    dp[i+1][bit][1] += dp[i][j][mode];
                                }
                            }
                        }
                    }else{
                        if (i+1==s){
                            dp[i+1][1][0] += dp[i][j][mode];
                        }else{
                            dp[i+1][0][0] += dp[i][j][mode];
                            dp[i+1][1][0] += dp[i][j][mode];
                        }
                    }
                }
            }
            res[s] = dp[n][0][0] + dp[n][0][1] + dp[n][1][0] + dp[n][1][1];
        }
        return res;
    };

    auto resa = f(a-1);
    auto resb = f(b);
    vector<ll> arr(SIZE+1);
    rep(i,0,SIZE+1){
        arr[i] = (resa[i] + resb[i]) % 2;
    }
    reverse(all(arr));
    ll ans = 0;
    rep(i,0,SIZE+1){
        if (arr[i]) ans += (1LL<<i);
    }
    cout << ans << endl;
    
    return 0;
}