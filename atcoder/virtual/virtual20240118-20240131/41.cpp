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

int main()
{
    string s;
    cin>>s;
    string t = "";
    ll n = s.size();
    rep(i,0,n){
        if (i+1<n && s[i]=='B'&&s[i+1]=='C'){
            t += 'X';
            i++;
        }else{
            t += s[i];
        }
    }

    auto arr = runLengthEncoding(t);
    ll ans = 0;
    n = arr.size();
    rep(i,0,n-1){
        if (arr[i].first=='A' && arr[i+1].first=='X'){
            ans += arr[i].second * arr[i+1].second;
            if (i+2<n && arr[i+2].first=='A'){
                arr[i+2].second += arr[i].second;
            }
        }
    }
    cout << ans << endl;
    
    // cout << fixed << setprecision(18);
    return 0;
}