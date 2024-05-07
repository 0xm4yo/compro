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
    ll n,m,e;
    cin>>n>>m>>e;
    vector<ll>u(e),v(e);
    rep(i,0,e)cin>>u[i]>>v[i];
    rep(i,0,e){u[i]--;v[i]--;}
    ll q;
    cin>>q;
    vector<ll>x(q);
    rep(i,0,q)cin>>x[i];

    vector<bool> ng(e);
    rep(i,0,q){
        x[i]--;
        ng[x[i]] = true;
    }
    dsu uf(n+m+1);
    rep(i,n,n+m){
        uf.merge(i,n+m);
    }

    rep(i,0,e){
        if (ng[i]) continue;
        uf.merge(u[i],v[i]);
    }

    ll ans = 0;
    rep(i,0,n){
        if (uf.same(i,n+m)) ans++;
    }

    vector<ll>arr;
    rrep(i,q-1,0){
        arr.push_back(ans);
        ll a = u[x[i]];
        ll b = v[x[i]];
        if (a>=n && b>=n) continue;
        if (a>b) swap(a,b);
        if (uf.same(a,n+m)&&uf.same(b,n+m))continue;
        
        if (uf.same(a,n+m)&&!uf.same(b,n+m)){
            int pre = uf.size(a);
            uf.merge(a,b);
            int now = uf.size(a);
            ans+=now-pre;
            continue;
        }

        if (!uf.same(a,n+m)&&uf.same(b,n+m)){
            int pre = uf.size(b);
            uf.merge(a,b);
            int now = uf.size(b);
            ans+=now-pre;
            continue;
        }
        uf.merge(a,b); 
    }
    reverse(all(arr));
    for (auto aa: arr) cout << aa << endl;


    // cout << fixed << setprecision(18);
    return 0;
}