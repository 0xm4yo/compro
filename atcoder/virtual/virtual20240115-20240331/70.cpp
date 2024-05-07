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

    ll h,w,r,c;
    cin>>h>>w>>r>>c;

    ll n;
    cin>>n;
    map<ll,vector<ll>>mpr,mpc;
    rep(i,0,n){
        ll rr,cc;
        cin>>rr>>cc;
        mpr[rr].push_back(cc);
        mpc[cc].push_back(rr);
    }
    for(auto [rr,vec]: mpr){
        sort(all(mpr[rr]));
    }
    for(auto [cc,vec]: mpc){
        sort(all(mpc[cc]));
    }

    ll q;
    cin>>q;
    while(q--){
        char d;
        ll l;
        cin>>d>>l;
        if (d=='L'){
            ll nex = c - l;
            chmax(nex, 1LL);
            if (mpr.find(r)==mpr.end()){
                c = nex;
            }else{
                auto itr = lower_bound(all(mpr[r]), c);
                auto itr2 = lower_bound(all(mpr[r]), nex);
                if (itr==itr2){
                    c = nex;
                }else{
                    itr--;
                    c = *itr+1;
                }
            }
        }
        if (d=='R'){
            ll nex = c + l;
            chmin(nex, w);
            if (mpr.find(r)==mpr.end()){
                c = nex;
            }else{
                auto itr = lower_bound(all(mpr[r]), c);
                auto itr2 = lower_bound(all(mpr[r]), nex);
                if (itr==itr2){
                    c = nex;
                    if (itr!=mpr[r].end() && *itr==nex) c--;
                }else{
                    c = *itr-1;
                }
            }
        }
        if (d=='U'){
            ll nex = r - l;
            chmax(nex, 1LL);
            if (mpc.find(c)==mpc.end()){
                r = nex;
            }else{
                auto itr = lower_bound(all(mpc[c]), r);
                auto itr2 = lower_bound(all(mpc[c]), nex);
                if (itr==itr2){
                    r = nex;
                }else{
                    itr--;
                    r = *itr+1;
                }
            }
        }
        if (d=='D'){
            ll nex = r + l;
            chmin(nex, h);
            if (mpc.find(c)==mpc.end()){
                r = nex;
            }else{
                auto itr = lower_bound(all(mpc[c]), r);
                auto itr2 = lower_bound(all(mpc[c]), nex);
                if (itr==itr2){
                    r = nex;
                    if (itr!=mpc[c].end() && *itr==nex) r--;
                }else{
                    r = *itr-1;
                }
            }
        }
        cout << r << " " << c << endl;
    }

    return 0;
}