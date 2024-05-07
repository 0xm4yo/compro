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
    reverse(all(res));
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);

    ll a,b;
    cin>>a>>b;
    a--;
    auto da = integer_digits(a);
    auto db = integer_digits(b);
    
    auto f = [](vector<int> d){
        ll n = d.size();
        // dp[i][j][mode]: i桁目までみて、状態j(0:4or9を含まない、1:4or9を含むことが確定）で状態mode（0:x以下が確定、1:x以下が未確定）のときの場合の数
        vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(2, vector<ll>(2)));
        dp[n][0][1] = 1;
        rrep(i,n,1){
            ll now = d[n-i];
            rep(j,0,2)rep(mode,0,2){
                if (mode){
                    rep(k,0,10){
                        if(k<now){
                            if (k==4 || k==9) dp[i-1][1][0] += dp[i][j][mode];
                            else dp[i-1][j][0] += dp[i][j][mode]; 
                        }else if(k==now){
                            if (k==4 || k==9) dp[i-1][1][1] += dp[i][j][mode];
                            else dp[i-1][j][1] += dp[i][j][mode];
                        }else{
                            continue;
                        }
                    }
                }else{
                    rep(k,0,10){
                        if (k==4 or k==9) dp[i-1][1][0] += dp[i][j][mode];
                        else dp[i-1][j][0] += dp[i][j][mode]; 
                    }
                }
            }
        }
        return dp[0][1][0] + dp[0][1][1];
    };

    cout << f(db) - f(da) << endl;
    
    // auto g = [](ll a, ll b){
    //     a++;
    //     ll res = 0;
    //     rep(x,a,b+1){
    //         auto arr = integer_digits(x);
    //         if (count(all(arr),4) || count(all(arr),9)) res++;
    //     }
    //     return res;
    // };

    // cout << g(a,b) << endl;
    return 0;
}