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

ll opsum(ll a, ll b){ return a+b; }
ll esum(){ return 0LL; }

struct S
{
    bool flag;
    ll l, r;
    S(){
        flag = true;
        l = -1;
        r = -1;
    }
    S(ll x){
        flag = true;
        l = x;
        r = x;      
    }
};

S op(S l, S r){
    S res;
    if (r.l==-1){
        r.l = INF;
        r.r = INF;
    }
    res.flag = l.flag & r.flag;
    if (l.r > r.l) res.flag = false;
    res.l = l.l;
    res.r = r.r;
    return res;
}

S e(){
    return S();
}

struct F
{
    ll x;
    F(ll y){ x = y; }
};

S mp(F f, S x){
    return x;
}

F comp(F f, F g){
    return f;
}

F id(){
    return F(0);
}

int main()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> t(n);
    rep(i,0,n) t[i] = s[i]-'a';
    ll q;
    cin>>q;
    vector<S> a(n);
    rep(i,0,n) a[i].l = t[i];
    rep(i,0,n) a[i].r = t[i];

    vector<segtree<ll,opsum,esum>> sum(26, segtree<ll,opsum,esum>(n));
    rep(i,0,n) sum[t[i]].set(i, 1);

    lazy_segtree<S,op,e,F,mp,comp,id> seg(a);

    while (q--){
        ll type;
        cin>>type;
        if (type==1){
            ll x;
            char c;
            cin>>x>>c;
            x--;
            sum[t[x]].set(x, 0);
            t[x] = c-'a';
            seg.set(x, t[x]);
            sum[t[x]].set(x, 1);
        }else{
            ll l,r;
            cin>>l>>r;
            l--;
            bool flag = seg.prod(l,r).flag;
            if (flag){
                ll st = seg.get(l).l;
                ll lt = seg.get(r-1).l;
                ll tot = 0;
                rep(i,st+1,lt){
                    tot += sum[i].all_prod();
                }
                tot += sum[st].prod(l,r);
                if (st!=lt) tot += sum[lt].prod(l,r);
                if (tot!=r-l) flag = false;
            }
            YesNo(flag);
        }
    }
   
    return 0;
}