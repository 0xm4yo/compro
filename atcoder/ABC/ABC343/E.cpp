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

    ll v1,v2,v3;
    cin>>v1>>v2>>v3;

    if(1029-3*v3-2*v2-v1!=0){
        YesNo(false);
        return 0;
    }

    YesNo(true);
    vector<vector<ll>> s(3, vector<ll>(3));

    auto g3 = [&](){
        ll minx = max({s[0][0], s[1][0], s[2][0]});
        ll maxx = min({s[0][0]+7, s[1][0]+7, s[2][0]+7});
        if (minx >= maxx) return 0LL;
        ll miny = max({s[0][1], s[1][1], s[2][1]});
        ll maxy = min({s[0][1]+7, s[1][1]+7, s[2][1]+7});
        if (miny >= maxy) return 0LL;
        ll minz = max({s[0][2], s[1][2], s[2][2]});
        ll maxz = min({s[0][2]+7, s[1][2]+7, s[2][2]+7});
        if (minz >= maxz) return 0LL;
        return (maxx-minx) * (maxy-miny) * (maxz-minz);
    };
    
    auto g2 = [&](ll a, ll b){
        ll minx = max(s[a][0], s[b][0]);
        ll maxx = min(s[a][0]+7, s[b][0]+7);
        if (minx >= maxx) return 0LL;
        ll miny = max(s[a][1], s[b][1]);
        ll maxy = min(s[a][1]+7, s[b][1]+7);
        if (miny >= maxy) return 0LL;
        ll minz = max(s[a][2], s[b][2]);
        ll maxz = min(s[a][2]+7, s[b][2]+7);
        if (minz >= maxz) return 0LL;
        return (maxx-minx) * (maxy-miny) * (maxz-minz);
    };

    s[0][0] = 0;
    s[0][1] = 0;
    s[0][2] = 0;
    rep(a,-7,8)rep(b,-7,8)rep(c,-7,8){
        s[1][0] = a;
        s[1][1] = b;
        s[1][2] = c;
        rep(d,-7,8)rep(e,-7,8)rep(f,-7,8){
            s[2][0] = d;
            s[2][1] = e;
            s[2][2] = f;
            ll s123 = g3();
            ll s12 = g2(0,1);
            ll s23 = g2(1,2);
            ll s31 = g2(2,0);
            ll res1 = 7*7*7*3 - 2*s12 - 2*s23 - 2*s31 + 3*s123;
            ll res2 = s12 + s23 + s31 - 3*s123;
            ll res3 = s123;
            if (res1==v1 && res2==v2 && res3==v3){
                rep(i,0,3)rep(j,0,3)cout << s[i][j] << " ";
                cout << endl;
                return 0;
            }
        }
    }
    
    return 0;
}