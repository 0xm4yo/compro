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
    ll n;
    cin>>n;
    vector<vector<pair<ll,ll>>> ok(101), ng(101);
    ll l = 1;
    ll r = n;
    ll mid = (l+r)/2;
    ok[0].push_back({l,mid});
    ng[0].push_back({mid+1,r});
    rep(i,1,101){
        for (auto [left,right]: ok[i-1]){
            l = left;
            r = right;
            if (l==r) continue;
            mid = (l+r)/2;
            ok[i].push_back({l,mid});
            ng[i].push_back({mid+1,r});
        }
        for (auto [left,right]: ng[i-1]){
            l = left;
            r = right;
            if (l==r) continue;
            mid = (l+r)/2;
            ok[i].push_back({l,mid});
            ng[i].push_back({mid+1,r});
        }
    }
    ll sz = 0;
    rep(i,0,101) if(ok[i].size()) sz++;
    cout << sz << endl;
    rep(i,0,sz){
        vector<ll> out;
        for (auto [left,right]: ok[i]){
            rep(j,left,right+1) out.push_back(j);
        }
        cout << out.size() << " ";
        sort(all(out));
        for (auto xx: out) cout << xx << " ";
        cout << endl;
    }

    vector<ll> v(n, true);
    string s;
    cin>>s;
    rep(i,0,sz){
        bool flag = (s[i]=='1');
        if (flag){
            for (auto [left,right]: ng[i]){
                rep(j,left-1,right) v[j] = false;
            }
        }else{
            for (auto [left,right]: ok[i]){
                rep(j,left-1,right) v[j] = false;
            }            
        }
    }
    rep(i,0,n){
        if (v[i]) cout << i+1 << endl;
    }
    
    // cout << fixed << setprecision(18);
    return 0;
}