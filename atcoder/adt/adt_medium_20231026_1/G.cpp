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

int main()
{
    ll n,m,p;
    cin>>n>>m>>p;
    vector<ll>a(n), b(m);
    rep(i,0,n)cin>>a[i];
    rep(i,0,m)cin>>b[i];
    sort(all(b));
    vector<ll>cum(m+1);
    rep(i,0,m)cum[i+1]=cum[i]+b[i];
    
    ll ans = 0;
    rep(i,0,n){
        ll x = p-a[i];
        ll idx = upper_bound(all(b), x) - b.begin();
        ans += p*(m-idx);
        ans += cum[idx]+a[i]*idx;
    }
    cout << ans << endl;

    return 0;
}