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

using P = pair<ll,ll>;
using P2 = pair<P,P>;

P f(P x, P y){
    P resf;  
    if (x.first==y.first){
        resf.first = x.first;
        resf.second = x.second + y.second;
    }else if(x.first<y.first){
        resf = y;
    }else{
        resf = x;
    }
    return resf;
}

P2 op(P2 a, P2 b){
    P2 res;
    res.first = f(a.first, b.first);
    if (res.first.first!=a.first.first){
        res.second = f(a.first, b.second);
        return res;
    }
    if (res.first.first!=b.first.first){
        res.second = f(b.first, a.second);
        return res;
    }
    res.second = f(b.second, a.second);
    return res;
}
P2 e(){ return {{0,0}, {0,0}}; }

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);

    ll n,q;
    cin>>n>>q;
    vector<P2>a(n);
    // map<ll,vector<ll>> mp;
    rep(i,0,n){
        ll aa;
        cin>>aa;
        a[i].first.first = aa;
        a[i].first.second = 1;
    }
    segtree<P2,op,e> seg(a);
    while(q--){
        ll c;
        cin>>c;
        if (c==1){
            ll p,x;
            cin>>p>>x;
            p--;
            seg.set(p, {{x,1},{0,0}});
        }else{
            ll l, r;
            cin>>l>>r;
            l--;
            auto res = seg.prod(l,r).second;
            if (res.first==0) cout << 0 << endl;
            else cout << res.second << endl;
        }
    }
    
    return 0;
}