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
    ll h,w;
    cin>>h>>w;
    vector<string> s(h);
    rep(i,0,h)cin>>s[i];
    vector<vector<char>> g(h,vector<char>(w));
    rep(i,0,h)rep(j,0,w)g[i][j]=s[i][j];
    rep(i,0,h)rep(j,0,w){
        if (g[i][j]=='>'){
            ll pos = j+1;
            while(pos<w){
                if (s[i][pos]=='v' || s[i][pos]=='^' ||  s[i][pos]=='<' ){
                    break;
                }else if (g[i][pos]=='.' || g[i][pos]=='>'  || g[i][pos] == '!'){
                    g[i][pos] = '!';
                    pos++;
                }else{
                    break;
                }
            }
        }else if(g[i][j]=='v'){
            ll pos = i+1;
            while(pos<h){
                if (s[pos][j]=='<' || s[pos][j]=='^' ||  s[pos][j]=='>' ){
                    break;
                }else if (g[pos][j]=='.' || g[pos][j]=='v' || g[pos][j] == '!'){
                    g[pos][j] = '!';
                    pos++;
                }else{
                    break;
                }
            }    
        }else if(g[i][j]=='<'){
            ll pos = j-1;
            while(pos>=0){
                if (s[i][pos]=='v' || s[i][pos]=='^' ||  s[i][pos]=='>'){
                    break;
                }else if (g[i][pos]=='.' || g[i][pos] == '!'){
                    g[i][pos] = '!';
                    pos--;
                }else{
                    break;
                }
            }    
        }else if(g[i][j]=='^'){
            ll pos = i-1;
            while(pos>=0){
                if (s[pos][j]=='>' || s[pos][j]=='^' ||  s[pos][j]=='<'){
                    break;
                }else if (g[pos][j]=='.' || g[pos][j] == '!'){
                    g[pos][j] = '!';
                    pos--;
                }else{
                    break;
                }
            }    
        }
    }
    queue<pair<ll,ll>> q;
    ll sh,sw,gh,gw;
    rep(i,0,h)rep(j,0,w) if(s[i][j]=='S'){
        sh=i; sw=j; break;
    }
    rep(i,0,h)rep(j,0,w) if(s[i][j]=='G'){
        gh=i; gw=j; break;
    }
    vector<vector<ll>>v(h,vector<ll>(w,INF));

    q.push({sh,sw});
    v[sh][sw] = 0;
    while(!q.empty()){
        auto [nh,nw] = q.front(); q.pop();
        rep(i,0,4){
            ll nxh = nh + DX[i];
            ll nxw = nw + DY[i];
            if (nxh<0 || nxw<0 || nxh>=h || nxw>=w) continue;
            if (v[nxh][nxw]!=INF)continue;
            if (g[nxh][nxw] == '.' || g[nxh][nxw] == 'G' ){
                v[nxh][nxw] = v[nh][nw] + 1;
                q.push({nxh,nxw});
            }
        }
    }
    if (v[gh][gw]==INF) cout << -1 << endl;
    else cout << v[gh][gw] << endl;
    
    // cout << fixed << setprecision(18);
    return 0;
}