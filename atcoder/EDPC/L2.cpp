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
const ll INF = (ll)3e15;

bool flag[3100][3100] = {false};
ll memo[3100][3100] = {0};

int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    function<ll(ll,ll)> f = [&](ll l, ll r){
        if (l==r) return a[l];
        if (flag[l][r])return memo[l][r];
        ll res = -INF;
        chmax(res, a[r] - f(l,r-1));
        chmax(res, a[l] - f(l+1,r));
        flag[l][r] = true;
        return memo[l][r] = res;        
    };
    cout << f(0,n-1) << endl;
    return 0;
}