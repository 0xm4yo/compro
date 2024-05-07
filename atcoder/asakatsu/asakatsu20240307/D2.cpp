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

    ll n,k,p;
    cin>>n>>k>>p;

    vector<ll> c(n);
    vector<vector<ll>> a(n, vector<ll>(k));
    rep(i,0,n){
        cin>>c[i];
        rep(j,0,k) cin>>a[i][j];
    }

    vector<map<vector<ll>,ll>> mp(n+1);
    vector<ll> init(k);
    mp[0][init] = 0;
    rep(i,0,n){
        auto itr = mp[i].begin();
        while(itr!=mp[i].end()){
            auto [vec, cost] = *itr;
            if (mp[i+1].find(vec)==mp[i+1].end()){
                mp[i+1][vec] = cost;
            }else{
                mp[i+1][vec] = min(mp[i+1][vec], cost);
            }
            auto now = vec;
            rep(j,0,k) now[j] = min(p, now[j]+a[i][j]);
            if (mp[i+1].find(now)==mp[i+1].end()){
                mp[i+1][now] = cost + c[i];
            }else{
                mp[i+1][now] = min(mp[i+1][now], cost + c[i]);
            }
            itr++;
        }
    }
    auto itr = mp[n].end();
    itr--;
    auto [lt, cost] = *itr;
    vector<ll> last(k, p);
    if (lt == last) cout << cost << endl;
    else cout << -1 << endl;
    
    return 0;
}