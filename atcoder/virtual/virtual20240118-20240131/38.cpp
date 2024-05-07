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
struct Cum2D{
    vector<vector<T>> cum;
    int h,w;
    // コンストラクタ
    Cum2D() {}
    Cum2D(vector<vector<T>>& arr){
        h = arr.size();
        w = arr[0].size();
        cum.resize(h+1, vector<T>(w+1, 0));
        // 累積和を計算
        for (int i=1; i<h+1; i++){
            for (int j=1; j<w+1; j++){
                cum[i][j] = arr[i-1][j-1] + cum[i][j-1] + cum[i-1][j] - cum[i-1][j-1];
            }
        }
    }
    // 0-indexed, 長方形領域 [h1,w1] から [h2,w2] までの和を取得
    T get(int h1, int w1, int h2, int w2){
        assert(h1<=h2 && w1<=w2);
        return cum[h2+1][w2+1] - cum[h2+1][w1] - cum[h1][w2+1] + cum[h1][w1];
    }
    // 0-indexed, 無限グリッド（範囲外）にも対応、長方形領域 [h1,w1] から [h2,w2] までの和を取得
    T get_overRange(long long h1, long long w1, long long h2, long long w2){
        assert(h1<=h2 && w1<=w2);
        auto f = [&](long long hh, long long ww){
            T res = cum[h][w] * (hh/h) * (ww/w);
            int remh = hh%h;
            int remw = ww%w;
            res += cum[remh][w] * (ww/w);
            res += cum[h][remw] * (hh/w);
            res += cum[remh][remw];
            return res;
        };
        return f(h2+1, w2+1) - f(h2+1, w1) - f(h1, w2+1) + f(h1, w1);
    }
};


int main()
{
    ll h,w;
    cin>>h>>w;
    vector<vector<ll>> a(h, vector<ll>(w));
    rep(i,0,h)rep(j,0,w)cin>>a[i][j];
    auto b = a;
    auto c = a;
    rep(i,0,h)rep(j,0,w){
        if ((i+j)%2){
            b[i][j] = 0;
        }else{
            c[i][j] = 0;
        }
    }
    Cum2D<ll> cum1(b), cum2(c);
    ll ans = 0;
    rep(i,0,h)rep(j,0,w){
        rep(k,i,h)rep(l,j,w){
            if (cum1.get(i,j,k,l)==cum2.get(i,j,k,l)) chmax(ans, (k-i+1)*(l-j+1));
        }
    }
    cout << ans << endl;
    // cout << fixed << setprecision(18);
    return 0;
}