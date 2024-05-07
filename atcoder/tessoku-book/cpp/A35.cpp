#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)1e15;

bool flag[2200][2200] = {false};
ll memo[2200][2200] = {0};

int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    
    function<ll(ll,ll)> f = [&](ll h, ll w){
        if (flag[h][w]) return memo[h][w];
        ll res = 0;
        if (h==n-1) return a[w];
        if (h%2){
            res = min(f(h+1,w), f(h+1,w+1));
        }else{
            res = max(f(h+1,w), f(h+1,w+1));
        }
        flag[h][w] = true;
        memo[h][w] = res;
        return res;
    };
    cout << f(0,0) << endl;
    
    return 0;
}