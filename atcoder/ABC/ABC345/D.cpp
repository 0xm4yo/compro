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

    ll n,h,w;
    cin>>n>>h>>w;

    vector<ll> a(n),b(n);
    rep(i,0,n)cin>>a[i]>>b[i];

    rep(s,1,1LL<<n){
        vector<ll>arr;
        rep(i,0,n){
            if (s&(1LL<<i)) arr.push_back(i);
        }
        ll temp = 0;
        for (auto idx: arr){
            temp += a[idx] * b[idx];
        }
        if (temp != h*w) continue;
        do{
            rep(t,0,1LL<<arr.size()){
                vector<vector<ll>> g(h, vector<ll>(w));
                bool flag = true;
                rep(j,0,arr.size()){
                    if (t&(1LL<<j)) swap(a[arr[j]], b[arr[j]]);
                    ll sh = -1;
                    ll sw = -1;
                    rep(ii,0,h){
                        rep(jj,0,w){
                            if (!g[ii][jj]){
                                sh = ii;
                                sw = jj;
                                break;
                            }
                        }
                        if (sh!=-1) break;
                    }
                    if (sh+a[arr[j]]>h){
                        if (t&(1LL<<j)) swap(a[arr[j]], b[arr[j]]);
                        flag = false;
                        break;
                    }
                    if (sw+b[arr[j]]>w){
                        if (t&(1LL<<j)) swap(a[arr[j]], b[arr[j]]);
                        flag = false;
                        break;                        
                    }
                    rep(ii,sh,sh+a[arr[j]])rep(jj,sw,sw+b[arr[j]]){
                        if (g[ii][jj]) flag = false;
                        g[ii][jj] = 1;
                    }
                    if (t&(1LL<<j)) swap(a[arr[j]], b[arr[j]]);
                    if (!flag) break;
                }
                if (flag){
                    YesNo(true);
                    return 0;
                }
            }
        }while(next_permutation(all(arr)));
    }
    YesNo(false);
    return 0;
}