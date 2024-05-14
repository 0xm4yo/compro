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
    cout << fixed << setprecision(18);

    vector<vector<ll>> c(3, vector<ll>(3));
    rep(i,0,3)rep(j,0,3)cin>>c[i][j];

    vector<ll> arr;
    rep(i,0,9) arr.push_back(i);

    vector<ll> n1 = {0,4,8};
    vector<ll> n2 = {2,4,6};

    ll tot = 0;
    ll yes = 0;
    do{
        tot++;
        vector<vector<ll>> now(3, vector<ll>(3));
        bool ok = true;
        for (auto a: arr){
            ll h = a/3;
            ll w = a%3;
            ll flag = 0;
            rep(i,0,3){
                if (h!=i) continue;
                map<ll,ll>mp;
                rep(j,0,3) mp[now[i][j]]++;
                for (auto [num, cnt]: mp){
                    if (num==0) continue;
                    if (cnt==2) flag = num;
                }
                if (flag) if(flag!=c[h][w]) ok = false;
            }
            flag = 0;
            rep(j,0,3){
                if (w!=j) continue;
                map<ll,ll>mp;
                rep(i,0,3) mp[now[i][j]]++;
                for (auto [num, cnt]: mp){
                    if (num==0) continue;
                    if (cnt==2) flag = num;
                }
                if (flag) if(flag!=c[h][w]) ok = false;
            }
            flag = 0;
            if (find(all(n1), a) != n1.end()){
                map<ll,ll>mp;
                for (auto x: n1){
                    mp[now[x/3][x%3]]++;
                }
                for (auto [num, cnt]: mp){
                    if (num==0) continue;
                    if (cnt==2) flag = num;
                }
                if (flag) if(flag!=c[h][w]) ok = false;                
            }
            flag = 0;
            if (find(all(n2), a) != n2.end()){
                map<ll,ll>mp;
                for (auto x: n2){
                    mp[now[x/3][x%3]]++;
                }
                for (auto [num, cnt]: mp){
                    if (num==0) continue;
                    if (cnt==2) flag = num;
                }
                if (flag) if(flag!=c[h][w]) ok = false;                
            }
            now[h][w] = c[h][w];
        }
        if (ok) yes++;
    }while(next_permutation(all(arr)));
    cout << (double)yes/(double)tot << endl;
    return 0;
}