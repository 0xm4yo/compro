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
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n),b(m);
    rep(i,0,n)cin>>a[i];
    rep(i,0,m)cin>>b[i];
    sort(all(a));
    sort(all(b));
    ll ans = INF;
    rep(i,0,m){
        ll x = b[i];
        auto itr = lower_bound(all(a), x);
        if (itr==a.begin()){
            chmin(ans, *itr-x);
        }else if(itr==a.end()){
            itr--;
            chmin(ans, x-*itr);
        }else{
            chmin(ans, *itr-x);
            itr--;
            chmin(ans, x-*itr);
        }
    }
    cout << ans << endl;

    return 0;
}