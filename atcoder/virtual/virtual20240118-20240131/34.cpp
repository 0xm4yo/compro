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

template<typename T>
struct Cum{
    vector<T> cum;
    // コンストラクタ
    Cum() {}
    Cum(vector<T>& arr){
        int n = arr.size();
        cum.resize(n+1,0);
        // 累積和を計算
        for (int i=0; i<n; i++){
            cum[i+1] = cum[i] + arr[i];
        }
    }
    // 0-indexed, 区間 [l,r) の和を取得
    T get(int l, int r){
        assert(l<=r);
        return cum[r] - cum[l];
    }
};

int main()
{
    ll n,q,x;
    cin>>n>>q>>x;
    vector<ll> w(n), a(3*n);
    rep(i,0,n)cin>>w[i];
    rep(i,0,3*n) a[i] = w[i%n];
    
    Cum<ll> cum(a);
    ll tot = accumulate(all(w), 0LL);

    ll base = (x/tot)*n;
    x %= tot;
    vector<vector<ll>> dp(60, vector<ll>(n));
    vector<ll> cnt(n);
    if (x){
        ll now = 0;
        ll r = 0;
        rep(l,0,n){
            while(now < x){
                now += w[r%n];
                r++;
            }
            now -= w[l];
            dp[0][l] = r%n;
            cnt[l] = base + r - l;
        }
    }else{
        rep(i,0,n) dp[0][i] = i;
        rep(i,0,n) cnt[i] = base;
    }

    rep(i,0,59)rep(j,0,n){
        ll nex = dp[i][j];
        dp[i+1][j] = dp[i][nex];
    }

    while(q--){
        ll k;
        cin>>k;
        ll now = 0;
        k--;
        rrep(i,59,0){
            if (k&(1LL<<i)){
                now = dp[i][now];
            }
        }
        cout << cnt[now] << endl;
    }
    
    // cout << fixed << setprecision(18);
    return 0;
}