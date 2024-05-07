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
    ll h,w,a,b;
    cin>>h>>w>>a>>b;
    
    queue<tuple<ll,ll,vector<vector<bool>>>> q;
    vector<vector<bool>> init(h,vector<bool>(w));
    q.push({a,b,init});
    ll ans = 0;

    while(!q.empty()){
        auto [c,d,arr] = q.front(); q.pop();

        if (c==0 && d==0){
            ans++;
            continue;
        }
        ll sh=-1,sw=-1;
        rep(i,0,h){
            rep(j,0,w){
                if (!arr[i][j]){
                    sh = i;
                    sw = j;
                    break;
                }
            }
            if (sh!=-1) break;
        }
        if (sh==-1 || sw==-1) continue;
        
        if (sh+1<h && c && !arr[sh+1][sw]){
            auto nex = arr;
            nex[sh][sw] = true;
            nex[sh+1][sw] = true;
            q.push({c-1,d,nex});
        }
        if (sw+1<w && c && !arr[sh][sw+1]){
            auto nex = arr;
            nex[sh][sw] = true;
            nex[sh][sw+1] = true;
            q.push({c-1,d,nex});
        }
        if (d){
            auto nex = arr;
            nex[sh][sw] = true;
            q.push({c,d-1,nex});            
        }
    }
    cout << ans << endl;
    
    // cout << fixed << setprecision(18);
    return 0;
}