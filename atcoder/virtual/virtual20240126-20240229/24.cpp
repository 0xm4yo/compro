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

    ll n,q;
    cin>>n>>q;
    vector<ll> ld(5000000, -1);
    vector<ll> pos(5000000, -1);
    rep(i,0,n) ld[i] = i;
    rep(i,0,n) pos[i] = i;
    vector<ll> ver(n);
    rep(i,0,n) ver[i] = i;
    vector<ll> inv(5000000,-1);
    rep(i,0,n) inv[i] = i;

    dsu uf(5000000);
    rep(i,0,n) uf.merge(i, i+2000000);
    ll box = n;
    ll k = n;
    while(q--){
        ll c;
        cin>>c;
        if (c==1){
            ll x,y;
            cin>>x>>y;
            x--;y--;
            uf.merge(ver[x], ver[y]);
            ld[uf.leader(ver[y])] = ver[x];
            ver[y] = box;
            inv[box] = y;
            ld[box] = box;
            box++;
        }else if(c==2){
            ll x;
            cin>>x;
            x--;
            uf.merge(k+2000000, ver[x]);
            ld[uf.leader(ver[x])] = ver[x];
            pos[k] = ver[x];
            k++;
        }else{
            ll x;
            cin>>x;
            x--;
            ll par = pos[x];
            // cout << uf.leader(par) << endl;
            ll ans = inv[ld[uf.leader(par)]];
            cout << ans + 1 << endl;            
        }
    }
    
    return 0;
}