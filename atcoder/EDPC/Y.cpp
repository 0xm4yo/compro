#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)3e15;

using mint = modint1000000007;

// k ≤ n ≤ 10^7  で法Pが素数のとき
const long long MOD = (long long)1e9+7;
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
    ll h,w,n;
    cin>>h>>w>>n;
    vector<pair<ll,ll>> rc;
    rep(i,0,n){
        ll r,c;
        cin>>r>>c;
        rc.push_back({r,c});
    }
    rc.push_back({1,1});
    rc.push_back({h,w});
    sort(all(rc));
    init_nCk(h+w+10);

    auto f = [&](ll a, ll b){
        auto [ax, ay] = rc[a];
        auto [bx, by] = rc[b];
        ll dx = bx - ax, dy = by - ay;
        if (dx < 0 || dy < 0) return 0LL;
        return nCk(dx+dy, dx);
    };

    vector<vector<mint>> dp(n+2, vector<mint>(2, 0));
    dp[0][1] = 1;
    rep(i,1,n+2){
        rep(j,0,i){
            dp[i][0] += dp[j][1] * f(j,i);
            dp[i][1] += dp[j][0] * f(j,i);
        }
    }

    mint ans = dp[n+1][0] - dp[n+1][1];

    cout << ans.val() << endl;

    return 0;
}