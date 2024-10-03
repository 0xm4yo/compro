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
ll dist2(ll x1, ll y1, ll x2, ll y2){ return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2); }

#define endl "\n" // インタラクティブの時はコメントアウトする

/*
    桁の数を b 進数で取得
    n を b 進数で表記したときの各桁の数字を上位桁から順に並べたリストを返す
*/
vector<int> integer_digits(long long n, int b = 10){
   assert(abs(b) >= 2);
   // n = 0
   if (n == 0) return vector<int>{0};

   // mod |b| をとって最下位桁から順に決定
   vector<int> res;
   while (n != 0) {
       int d = smod(n, abs(b));
       res.push_back(d);
       n = (n - d) / b;
   }

   // 上位桁から順になるように並べ直す
//    reverse(all(res));
   return res;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);

    ll n;
    cin>>n;
    vector<ll> pow10 = {1};
    rep(i,0,16) pow10.push_back(pow10.back()*10);
    
    auto arr = integer_digits(n);
    while(arr.size()<17){
        arr.push_back(0);
    }
    
    ll ans = 0;
    rep(keta,1,150){
        vector<vector<vector<vector<ll>>>> dp(16, vector<vector<vector<ll>>>(keta, vector<vector<ll>>(keta+1, vector<ll>(2))));
        dp[15][0][0][1] = 1;
        rrep(i,15,1)rep(j,0,keta)rep(l,0,keta+1)rep(mode,0,2){
            ll nex = arr[i-1];
            if (mode){
                rep(k,0,nex+1){
                    if (l+k>keta) continue;
                    if(k==nex) dp[i-1][(j+k*pow10[i-1])%keta][l+k][1] += dp[i][j][l][mode];
                    else dp[i-1][(j+k*pow10[i-1])%keta][l+k][0] += dp[i][j][l][mode];
                }
            }else{
                rep(k,0,10){
                    if (l+k>keta) continue;
                    dp[i-1][(j+k*pow10[i-1])%keta][l+k][0] += dp[i][j][l][mode];
                }                
            }
        }
        ans += dp[0][0][keta][0] + dp[0][0][keta][1];
    }
    cout << ans << endl;

    
    return 0;
}