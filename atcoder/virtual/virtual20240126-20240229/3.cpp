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

using S = ll;

S op(S l, S r){
    return min(l, r);
}
S e(){
    return INF;
}

using F = ll;
S mp(F f, S x){
    return f + x;
}
F comp(F f, F g){
    return f + g;
}
F id(){
    return 0LL;
}

int main()
{
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<S>cum(n+1);
    rep(i,0,n){
        if (s[i]=='(') cum[i+1] = cum[i] + 1;
        else cum[i+1] = cum[i] - 1;
    }
    
    lazy_segtree<S,op,e,F,mp,comp,id> seg(cum);
    while (q--){
        ll c;
        cin>>c;
        ll l,r;
        cin>>l>>r;
        if (c==1){
            if (s[l-1]==s[r-1])continue;
            if (s[l-1]=='('){
                seg.apply(l,r,-2);
            }else{
                seg.apply(l,r,2);
            }
            swap(s[l-1],s[r-1]);
        }else{
            bool flag = true;
            ll base = seg.get(l-1);
            if (seg.get(r)!=base) flag = false;
            if (seg.prod(l,r+1)<base) flag = false;
            YesNo(flag);
        }
    }

    return 0;
}
