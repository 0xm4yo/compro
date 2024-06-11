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
const vector<int> DX = { 1, -1, 1, -1 };
const vector<int> DY = { 1, 1, -1, -1 };
const long long INF = 4004004003104004004LL; // (int)INF = 1010931620;
ll coordinate(ll h, ll w, ll W){ return h*W + w; } // 二次元座標を一次元座標に変換
ll dist2(ll x1, ll y1, ll x2, ll y2){ return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2); }

#define endl "\n" // インタラクティブの時はコメントアウトする

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);
    ll n;
    cin>>n;
    ll ax,ay;
    cin>>ax>>ay;
    ax--;ay--;
    ll bx,by;
    cin>>bx>>by;
    bx--;by--;
    vector<string>s(n);
    rep(i,0,n)cin>>s[i];
    vector<vector<ll>> v(n, vector<ll>(n,-1));
    vector<vector<vector<bool>>> vh(n, vector<vector<bool>>(n, vector<bool>(4)));
    
    priority_queue_rev<tuple<ll,ll,ll>> hq;
    hq.push({0,ax,ay});
    
    while(!hq.empty()){
        auto [cnt,h,w] = hq.top(); hq.pop();
        if (v[h][w]!=-1) continue;
        v[h][w] = cnt;
        rep(i,0,4){
            rep(d,1,2000){
                ll nh = h + DX[i]*d;
                ll nw = w + DY[i]*d;
                if (nh<0 || nh>=n || nw<0 || nw>=n){
                    break;
                }
                if (s[nh][nw]=='#') break;
                if (vh[nh][nw][i]) break;
                vh[nh][nw][i] = true;
                hq.push({cnt+1,nh,nw});
            }
        }
    }
    cout << v[bx][by] << endl;
    
    return 0;
}
