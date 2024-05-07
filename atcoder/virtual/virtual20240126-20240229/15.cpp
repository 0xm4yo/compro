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
    
    vector<pair<ll,ll>> arr;
    rep(i,1,n+1){
        ll len = 1;
        while(len+i-1<=n){
            arr.push_back({i,i+len-1});
            len *= 2;
        }
    }
    map<pair<ll,ll>,ll> mp;
    rep(i,0,arr.size()){
        mp[arr[i]] = i+1;
    }

    cout << arr.size() << endl;
    for (auto [l,r]: arr){
        cout << l << " " << r << endl;
    }

    ll q;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        ll len = 1;
        while(l+len*2-1<=r){
            len *= 2;
        }
        ll a = mp[{l,l+len-1}];
        len = 1;
        while(r-len*2+1>=l){
            len *= 2;
        }
        ll b = mp[{r-len+1,r}];
        cout << a << " " << b << endl;
    }
    
    // cout << fixed << setprecision(18);
    return 0;
}