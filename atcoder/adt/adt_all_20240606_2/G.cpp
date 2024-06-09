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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll q;
    cin>>q;

    ll m2 = 0;
    ll m3 = 0;
    vector<ll> t(q),x(q);
    vector<char> c(q);
    rep(i,0,q) cin>>t[i]>>x[i]>>c[i];
    ll last = -1;
    ll mode = -1;
    rep(i,0,q){
        if (t[i]!=1){
            last = i;
            mode = t[i];
        }
    }
    vector<char> arr(n);
    rep(i,0,n) arr[i] = s[i];
    rep(i,0,last){
        if (t[i]==1) arr[x[i]-1] = c[i];
    }
    rep(i,0,n){
        if (mode==2){
            if (0 <= arr[i]-'A' && arr[i]-'A' < 26){
                arr[i] = char('a'+arr[i]-'A');
            }
        }
        if (mode==3){
            if (0 <= arr[i]-'a' && arr[i]-'a' < 26){
                arr[i] = char('A'+arr[i]-'a');
            }
        }
    }
    rep(i,last,q){
        if (t[i]==1) arr[x[i]-1] = c[i];
    }
    rep(i,0,n){
        cout << arr[i];
    }

    
    return 0;
}