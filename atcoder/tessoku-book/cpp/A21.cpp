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

bool flag[2100][2100] = {false};
ll memo[2100][2100] = {0};

int main()
{
    ll n;
    cin>>n;
    vector<ll> p(n),a(n);
    rep(i,0,n)cin>>p[i]>>a[i];
    rep(i,0,n)p[i]--;
    function<ll(ll,ll)> f = [&](ll l, ll r){
        if (l>=r) return 0LL;
        if (flag[l][r]) return memo[l][r];
        ll res = 0;
        ll la = 0, ra = 0;
        if (l <= p[l] && p[l] <= r) la = a[l];
        if (l <= p[r] && p[r] <= r) ra = a[r];
        chmax(res, f(l,r-1) + ra);
        chmax(res, f(l+1, r) + la);
        flag[l][r] = true;
        memo[l][r] = res;
        return res;
    };
    cout << f(0,n-1) << endl;
    return 0;
}