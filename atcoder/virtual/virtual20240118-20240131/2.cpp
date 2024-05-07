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

vector<pair<char, long long>> runLengthEncoding(string s){
    long long n = s.length();
    vector<pair<char, long long>> res;
    long long l = 0;
    while (l < n){
        long long r = l + 1;
        while (r < n && s[l] == s[r]) r++;
        res.push_back(make_pair(s[l], r-l));
        l = r;
    }
    return res;
}

using mint = modint1000000007;

int main()
{
    ll h,w;
    cin>>h>>w;
    vector<string>s(h);
    rep(i,0,h)cin>>s[i];

    vector<string>t(w);
    rep(j,0,w)rep(i,0,h){
        t[j] += s[i][j];
    }

    vector<vector<ll>> sa(h,vector<ll>(w));
    vector<vector<ll>> ta(w,vector<ll>(h));
    rep(i,0,h){
        auto arr = runLengthEncoding(s[i]);
        ll now = 0;
        for (auto [c,cnt]: arr){
            if (c=='.'){
                ll temp = cnt;
                while(temp){
                    sa[i][now] = cnt;
                    now++;
                    temp--;
                }
            }else{
                ll temp = cnt;
                while(temp){
                    sa[i][now] = 0;
                    now++;
                    temp--;
                }
            }
        }
    }
    rep(j,0,w){
        auto arr = runLengthEncoding(t[j]);
        ll now = 0;
        for (auto [c,cnt]: arr){
            if (c=='.'){
                ll temp = cnt;
                while(temp){
                    ta[j][now] = cnt;
                    now++;
                    temp--;
                }
            }else{
                ll temp = cnt;
                while(temp){
                    ta[j][now] = 0;
                    now++;
                    temp--;
                }
            }
        }
    }
    mint temp = 0;
    ll k = 0;
    rep(i,0,h)rep(j,0,w){
        if (s[i][j]=='#') continue;
        k++;
        ll tot = sa[i][j]+ta[j][i]-1;
        temp += ((mint)1-(mint)(1)/(mint)(pow_mod(2,tot,1000000007)));
    }
    mint ans = temp*pow_mod(2,k,1000000007);

    cout << ans.val() << endl;
    // cout << fixed << setprecision(18);
    return 0;
}