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

map<long long, int> primeFactorization(long long n){
    map<long long, int> res;
    for (long long i=2; i*i<=n; i++){
        while (n % i == 0){ res[i]++; n /= i;}
    }
    if(n != 1) res[n] = 1;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);
    
    ll n;
    cin>>n ;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];

    ll base2 = INF;
    ll base3 = INF;
    ll ans = 0;
    set<pair<ll,ll>> st;
    rep(i,0,n){
        auto v = primeFactorization(a[i]);
        for (auto [b,cnt]: v){
            if (b==1) continue;
            if (b!=2 && b!=3){
                st.insert({(ll)pow(b,cnt),cnt});
                continue;
            }
            if (b==2) chmin(base2, (ll)cnt);
            if (b==3) chmin(base3, (ll)cnt);
            ans += cnt;
        }       
    }
    bool flag2 = true;
    bool flag3 = true;
    rep(i,0,n){
        if (a[i]%2) flag2 = false;
        if (a[i]%3) flag3 = false;
    }
    if (!flag2) base2 = 0;
    if (!flag3) base3 = 0;
    ans -= base2*n;
    ans -= base3*n;
    for (auto [b,cnt]: st){
        rep(i,0,n){
            if (a[i]%b){
                cout << -1 << endl;
                return 0;
            }
            a[i] /= b;
        }
    }

    cout << ans << endl;

    return 0;
}