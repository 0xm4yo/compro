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

bool flag[410][410] = {false};
ll memo[410][410] = {0};

int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    vector<ll>cum(n+1);
    rep(i,0,n){
        cum[i+1] = cum[i] + a[i];
    }
    auto c = [&](ll l, ll r){
        return cum[r+1] - cum[l];
    };

    function<ll(ll,ll)> f = [&](ll l, ll r){
        if (l==r) return 0LL;
        if (flag[l][r]) return memo[l][r];
        ll res = INF;
        rep(i,l,r){
            chmin(res, f(l,i) + f(i+1,r) + c(l,i) + c(i+1,r));
        }
        flag[l][r] = true;
        return memo[l][r] = res;
    };
    cout << f(0,n-1) << endl;
    return 0;
}