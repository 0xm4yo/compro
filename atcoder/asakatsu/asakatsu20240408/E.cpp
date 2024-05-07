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
    
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    vector<ll> last = {c,b,a};
    vector<ll> l(n);
    rep(i,0,n)cin>>l[i];

    ll ans = INF;
    rep(s, 1, 1LL<<n){
        if (popcount(s)<3) continue;
        vector<ll> arr;
        rep(j,0,n){
            if (s&(1LL<<j)) arr.push_back(j);
        }
        function<void(ll, vector<ll>)> dfs = [&](ll now, vector<ll> vec){
            if (now==arr.size()){
                if (find(all(vec), 0)==vec.end()) return ;
                if (find(all(vec), 1)==vec.end()) return ;
                if (find(all(vec), 2)==vec.end()) return ;
                ll aa = 0;
                ll bb = 0;
                ll cc = 0;
                rep(i,0,arr.size()){
                    if (vec[i]==0) aa += l[arr[i]];
                    if (vec[i]==1) bb += l[arr[i]];
                    if (vec[i]==2) cc += l[arr[i]];
                }
                vector<ll> v = {aa,bb,cc};
                sort(all(v));
                ll score = (arr.size()-3) * 10;
                score += abs(last[0] - v[0]);
                score += abs(last[1] - v[1]);
                score += abs(last[2] - v[2]);
                chmin(ans, score);
                return ;
            }
            rep(i,0,3){
                vec[now] = i;
                dfs(now+1, vec);
            }
        };
        vector<ll> vv(arr.size(),-1);
        dfs(0,vv);
    }

    cout << ans << endl;


    
    return 0;
}