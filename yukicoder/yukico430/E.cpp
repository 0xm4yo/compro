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

using mint = modint;

mint op(mint a, mint b){ return a+b; }
mint e(){ return 0; }

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);

    int m = 543995951;
    mint::set_mod(m);
    ll n,l,q;
    cin>>n>>l>>q;

    vector<vector<ll>> a(n, vector<ll>(l));
    rep(i,0,n){
        string s;
        cin>>s;
        rep(j,0,l){
            char c = s[j];
            a[i][j] = c - 'a' + 1;
        }     
    }

    vector<segtree<mint,op,e>> seg(n, segtree<mint,op,e>(l));
    ll b = 117;
    rep(i,0,n){
        mint now = 1;
        rep(j,0,l){
            now *= b;
            seg[i].set(j, now*a[i][j]);
        }
    }

    while(q--){
        ll type;
        cin>>type;
        if (type==1){
            ll k;
            char c,d;
            cin>>k>>c>>d;
            k--;
            rep(i,0,n){
                if (a[i][k]==c-'a'+1){
                    mint now = pow_mod(b, k+1, m);
                    seg[i].set(k, now*(d-'a'+1));
                    a[i][k] = d-'a'+1;
                }
            }
        }else{
            string t;
            cin>>t;
            mint now = 1;
            mint hash = 0;
            rep(i,0,t.size()){
                now *= b;
                hash += now * (t[i]-'a'+1);
            }
            ll ans = 0;
            rep(i,0,n){
                mint sh = seg[i].prod(0, t.size());
                if (sh == hash) ans++;
            }
            cout << ans << endl;
        }
    }
    
    return 0;
}