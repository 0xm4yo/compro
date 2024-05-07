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

    ll h,w;
    cin>>h>>w;
    vector<string>s(h);
    rep(i,0,h)cin>>s[i];
    vector<vector<bool>> g(h,vector<bool>(w));
    ll sh = -1;
    ll sw = -1;
    rep(i,0,h)rep(j,0,w){
        if (s[i][j]=='S'){
            sh = i;
            sw = j;
            break;
        }
    }
    queue<pair<ll,ll>> q;
    q.push({sh,sw});
    g[sh][sw] = 0;
    dsu uf(h*w);   
    while(!q.empty()){
        auto [nh,nw] = q.front(); q.pop();
        rep(i,0,4){
            ll nxh = nh + DX[i];
            ll nxw = nw + DY[i];
            if (nxh<0 || nxh>=h || nxw<0 || nxw>=w) continue;
            if (s[nxh][nxw]!='.') continue;
            if (!(nh==sh && nw==sw)) uf.merge(coordinate(nh,nw,w), coordinate(nxh,nxw,w));
            if (g[nxh][nxw]) continue;
            g[nxh][nxw] = true;
            q.push({nxh,nxw});
        }
    }
    rep(i,0,4)rep(j,i+1,4){
        ll h1 = sh + DX[i];
        ll w1 = sw + DY[i];
        ll h2 = sh + DX[j];
        ll w2 = sw + DY[j];
        if (h1<0 || h1>=h || w1<0 || w1>=w) continue;
        if (h2<0 || h2>=h || w2<0 || w2>=w) continue;
        if (uf.same(coordinate(h1,w1,w), coordinate(h2,w2,w))){
            YesNo(true);
            return 0;
        }
    }
    YesNo(false);
    
    
    return 0;
}