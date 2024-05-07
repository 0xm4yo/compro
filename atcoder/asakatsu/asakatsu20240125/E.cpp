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
    ll n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    queue<ll> q;
    vector<bool> v(n);
    rep(i,0,n-m+1){
        bool flag = true;
        rep(j,0,m){
            if (s[i+j]!=t[j]) flag = false; 
        }
        if (flag) q.push(i);
    }
    while(!q.empty()){
        ll now = q.front(); q.pop();
        rep(i,0,m){
            v[now+i] = true;
        }
        ll l = now;
        rep(st,l-m+1,l){
            if (st<0) continue;
            bool flag2 = true;
            bool all1 = true;
            rep(j,0,m){
                if (st+j>=n){
                    all1 = true;break;
                }
                if (!v[st+j]) all1 = false;
                if (!(v[st+j]|s[st+j]==t[j])) flag2 = false;
            }
            if (all1) continue;
            if (flag2) q.push(st);
        }


        ll r = now+m;
        rep(st,r-m+1,r+m){
            if (st>=n) break;
            bool flag2 = true;
            bool all1 = true;
            rep(j,0,m){
                if (st+j>=n){
                    all1 = true;break;
                }
                if (!v[st+j]) all1 = false;
                if (!(v[st+j]|s[st+j]==t[j])) flag2 = false;
            }
            if (all1) continue;
            if (flag2) q.push(st);
        }    
    }
    bool flag = true;
    rep(i,0,n) if(!v[i]) flag = false;
    YesNo(flag);
    
    // cout << fixed << setprecision(18);
    return 0;
}