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

using mint = modint1000000007;

// n が固定かつ n が巨大 (k ≤ 10^7, n ≤ 10^9) で法 P が素数のとき
const long long MOD = (long long)1e9+7;
vector<long long> fact_inv, inv, COM;
// init_nCk: 二項係数のための前処理
// 前処理の計算量: O(k)
void init_nCk(int n, int SIZE) {
    fact_inv.resize(SIZE + 5);
    inv.resize(SIZE + 5);
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < SIZE + 5; i++) {
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fact_inv[i] = fact_inv[i-1] * inv[i] % MOD;
    }
    COM.resize(SIZE + 5);
    COM[0] = 1;
    for (int i = 1; i < SIZE + 5; i++) {
        COM[i] = COM[i-1] * ((n-i+1) * inv[i] % MOD) % MOD;
    }
}
// nCk: MODでの二項係数を求める(前処理 int_nCk が必要)
// クエリの計算量: O(1)
long long nCk(int k) {
    assert(!(k < 0));
    return COM[k];
}


int main()
{
    ll n,a,b;
    cin>>n>>a>>b;
    ll mod = 1000000007;
    mint ans = pow_mod(2,n,mod)-1;
    init_nCk(n, 200100);
    ans -= nCk(a);
    ans -= nCk(b);
    cout << ans.val() << endl;
    // cout << fixed << setprecision(18);
    return 0;
}