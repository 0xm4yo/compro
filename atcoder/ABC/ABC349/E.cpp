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

    vector<ll> a(9);
    rep(i,0,9)cin>>a[i];

    
    function<bool(ll,vector<ll>)> f = [&](ll mode, vector<ll> arr){
        bool flag = false;
        flag |= (arr[0] != -1 && arr[0] == arr[1] && arr[1] == arr[2]);
        flag |= (arr[3] != -1 && arr[3] == arr[4] && arr[4] == arr[5]);
        flag |= (arr[6] != -1 && arr[6] == arr[7] && arr[7] == arr[8]);

        flag |= (arr[0] != -1 && arr[0] == arr[3] && arr[3] == arr[6]);
        flag |= (arr[1] != -1 && arr[1] == arr[4] && arr[4] == arr[7]);
        flag |= (arr[2] != -1 && arr[2] == arr[5] && arr[5] == arr[8]);
        
        flag |= (arr[0] != -1 && arr[0] == arr[4] && arr[4] == arr[8]);
        flag |= (arr[2] != -1 && arr[2] == arr[4] && arr[4] == arr[6]);
        if (flag) return false;

        if (find(all(arr), -1)==arr.end()){
            ll x = 0;
            ll y = 0;
            rep(i,0,9){
                if (arr[i]) x += a[i];
                else y += a[i];
            }
            if (x>y) return false;
            else return true;
        }

        rep(i,0,9){
            if (arr[i]!=-1) continue;
            auto nex = arr;
            nex[i] = mode;
            if (!f(mode^1, nex)) return true;
        }
        return false;
    };

    vector<ll> init(9,-1);
    if (f(1, init)) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0;
}