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
const ll INF = (ll)1e18+10;

int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    ll same = 0;
    rep(i,0,n){
        if (i+1==a[i]) same++;
    }
    ll temp = 0;
    rep(i,0,n){
        if (a[i]>a[a[i]-1] && i+1==a[a[i]-1]) temp++;
    }
    ll ans = same*(same-1)/2 + temp;
    cout << ans << endl;
    return 0;
}