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

#define endl "\n" // インタラクティブの時はコメントアウトする

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);

    /*
    Mo's アルゴリズム
    verify: https://atcoder.jp/contests/abc174/tasks/abc174_f
    参考: https://ei1333.hateblo.jp/entry/2017/09/11/211011
    1. 配列の要素が不変
    2. クエリを先読みできる
    3. 区間 [l,r) の結果から区間[l+1,r), [l-1,r), [l,r-1), [l,r+1) の結果を計算できる
    */ 
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i,0,n) cin >> a[i];
    rep(i,0,n) a[i]--;
    
    int window = max(1, int(n/sqrt(q))); // 区間を区切る領域サイズ
    int nl = 0, nr = 0; // [nl, nr): 現在の計算済み区間
    vector<ll> res(q); // 各クエリの結果を格納する配列
    
    // 問題に応じて書き換える
    vector<int> cnt(2000200); // cnt[i]: 区間内に i が何個あるか
    ll ans = 0;
    
    // index: 各クエリのインデックスを管理する配列
    vector<int> l(q), r(q), index(q);
    rep(i,0,q){
        cin >> l[i] >> r[i];
        l[i]--;
    }
    for (int i=0; i<q; i++) index[i] = i;
    
    // ソート
    sort(all(index), [&](int a, int b){
        if (l[a]/window != l[b]/window) return l[a] < l[b];
        if (l[a]/window % 2) return r[a] > r[b];
        else return r[a] < r[b];
    });
    
    auto f = [](ll x){
        ll res = x*(x-1)*(x-2);
        res /= 6;
        return res;
    };

    // 問題に応じて書き換える
    auto add = [&](int idx){
        ll x = a[idx];
        ans -= f(cnt[x]);
        cnt[x]++;
        ans += f(cnt[x]);
    };

    // 問題に応じて書き換える
    auto del = [&](int idx){
        ll x = a[idx];
        ans -= f(cnt[x]);
        cnt[x]--;
        ans += f(cnt[x]);
    };
    
    for (auto nex: index){
        // クエリの区間に一致するまで、現在の区間を拡張 or 縮小
        while (nl > l[nex]) add(--nl);
        while (nr < r[nex]) add(nr++);
        while (nl < l[nex]) del(nl++);
        while (nr > r[nex]) del(--nr);
    
        // 問題に応じて書き換える
        // クエリの計算結果
        res[nex] = ans;
    }
    
    rep(i,0,q) cout << res[i] << endl;    
    
    return 0;
}