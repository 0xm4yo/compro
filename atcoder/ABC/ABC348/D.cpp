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

    vector<string> s(h);
    rep(i,0,h)cin>>s[i];

    ll n;
    cin>>n;
    vector<ll>r(n),c(n),e(n);
    rep(i,0,n)cin>>r[i]>>c[i]>>e[i];
    rep(i,0,n){r[i]--;c[i]--;}
    map<pair<ll,ll>,ll> mp;
    rep(i,0,n){
        mp[{r[i],c[i]}] = e[i];
    }

    ll sh = -1;
    ll sw = -1;
    ll th = -1;
    ll tw = -1;
    rep(i,0,h)rep(j,0,w){
        if (s[i][j]=='S'){
            sh = i;
            sw = j;
        }
        if (s[i][j]=='T'){
            th = i;
            tw = j;
        }
    }
    
    queue<pair<ll,ll>> q;
    q.push({sh, sw});
    set<pair<ll,ll>> st;
    st.insert({sh,sw});
    while(!q.empty()){
        auto [hh, ww] = q.front(); q.pop();
        ll d = mp[{hh,ww}];
        vector<vector<ll>> g(h, vector<ll>(w, -1));
        queue<pair<ll,ll>> q2;
        q2.push({hh,ww});
        g[hh][ww] = d;
        if (g[hh][ww]<=0) continue;
        while(!q2.empty()){
            auto [nh, nw] = q2.front(); q2.pop();
            rep(i,0,4){
                ll nxh = nh + DY[i];
                ll nxw = nw + DX[i];
                if (nxh<0 || nxh>=h || nxw<0 || nxw>=w) continue;
                if (s[nxh][nxw]=='#') continue;
                if (g[nxh][nxw]!=-1) continue;
                g[nxh][nxw] = g[nh][nw] - 1;
                if (nxh==th && nxw==tw){
                    cout << "Yes" << endl;
                    return 0;
                }
                if (g[nxh][nxw]>0) q2.push({nxh, nxw});
            }
        }
        rep(i,0,n){
            if (g[r[i]][c[i]]>=0){
                if (st.find({r[i],c[i]})==st.end() && g[r[i]][c[i]]<e[i]){
                    st.insert({r[i],c[i]});
                    q.push({r[i],c[i]});
                }
            }
        }
    }
    cout << "No" << endl;

    return 0;
}