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

using mint = modint998244353;

// k ≤ n ≤ 10^7  で法Pが素数のとき
const long long MOD = (long long)998244353;
vector<long long> fact, fact_inv, inv;
// init_nCk: 二項係数のための前処理
// 前処理の計算量: O(n)
void init_nCk(int SIZE) {
    fact.resize(SIZE + 5);
    fact_inv.resize(SIZE + 5);
    inv.resize(SIZE + 5);
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < SIZE + 5; i++) {
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        fact_inv[i] = fact_inv[i-1] * inv[i] % MOD;
    }
}
// nCk: MODでの二項係数を求める(前処理 int_nCk が必要)
// クエリ計算量: O(1)
long long nCk(int n, int k) {
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    return fact[n] * (fact_inv[k] * fact_inv[n-k] % MOD) % MOD;
}

int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> indeg(n);
    rep(i,0,m){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        indeg[u]++;
        indeg[v]++;
    }

    ll ev = 0, od = 0;
    rep(i,0,n){
        if (indeg[i]%2) od++;
        else ev++;
    }

    init_nCk(n);
    mint ans = 0;
    rep(i,0,k+1){
        if (ev<i) continue;
        if (od<k-i) continue;
        if ((k-i)%2) continue;
        ans += nCk(ev, i) * nCk(od, k-i);
    }
    cout << ans.val() << endl;

    
    // cout << fixed << setprecision(18);
    return 0;
}