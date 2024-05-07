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
    vector<ll>x(n),y(n);
    rep(i,0,n)cin>>x[i]>>y[i];
    ll ans = 0;
    rep(i,0,n)rep(j,i+1,n)rep(k,j+1,n){
        ll x1 = x[j] - x[i];
        ll y1 = y[j] - y[i];
        ll x2 = x[k] - x[i];
        ll y2 = y[k] - y[i];
        ll s = abs(x1*y2-x2*y1);
        if (s==0) continue;
        if (s%2==0) ans++;
    }
    cout << ans << endl;
    return 0;
}