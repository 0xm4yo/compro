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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];

    vector<bool> v(n);
    priority_queue<pair<ll,ll>> hq1;
    priority_queue_rev<pair<ll,ll>> hq2;

    vector<pair<ll,ll>>st;
    rep(i,0,m) st.push_back({a[i],i});
    sort(all(st));
    ll now = 0;
    rep(i,0,k){
        v[st[i].second] = true;
        hq1.push(st[i]);
        now += st[i].first;
    }
    rep(i,k,m) hq2.push(st[i]);

    cout << now << endl;
    rep(i,1,n-m+1){
        while(!hq1.empty()){
            auto [x,pos] = hq1.top();
            if (pos<i) hq1.pop();
            else break;
        }
        while(!hq2.empty()){
            auto [x,pos] = hq2.top();
            if (pos<i) hq2.pop();
            else break;
        }

        ll nex = i+m-1;
        hq2.push({a[nex],nex});

        ll pre = i-1;
        if (v[pre]){
            v[pre] = false;
            now -= a[pre];     
            auto [x,pos] = hq2.top(); hq2.pop();
            v[pos] = true;
            now += x;
            hq1.push({x,pos});
        }

        if (hq2.empty()){
            cout << now << endl;
            continue;
        }

        auto [x1,p1] = hq1.top();
        auto [x2,p2] = hq2.top();
        if (x1>x2){
            v[p1] = false;
            now -= x1;
            hq1.pop();
            hq2.push({x1,p1});
            v[p2] = true;
            now += x2;
            hq2.pop();
            hq1.push({x2,p2});
        }
        cout << now << endl;

    }


    
    // cout << fixed << setprecision(18);
    return 0;
}