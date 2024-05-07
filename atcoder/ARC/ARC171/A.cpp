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

int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n,a,b;
        cin>>n>>a>>b;
        bool flag = true;
        if (n<a){
            YesNo(false);
            continue;
        }
        // AC
        // if (n<=a*2){
        //     ll tot = (n-a)*(n-a);
        //     if (tot<b) flag = false;
        // }else{
        //     ll tot = (n+1)/2 * a;
        //     tot += (n+1)/2 * (n-2*a);
        //     if (tot<b) flag = false;
        // }

        if (n/2<=a){
            ll tot = (n-a)*(n-a);
            if (tot<b) flag = false;
        }else{
            ll tot = a*((n+1)/2);
            tot += (n-2*a) * ((n+1)/2);
            if (tot<b) flag = false;
        }
        YesNo(flag);
    }
    
    // cout << fixed << setprecision(18);
    return 0;
}