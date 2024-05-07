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
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    ll a1 = a[0];
    ll a2 = a[1];
    vector<ll>arr;
    rep(i,2,n) arr.push_back(a[i]);
    sort(all(arr));
    ll ans = INF;
    rep(i,0,n-2-m+1){
        ll mi = arr[i];
        ll ma = arr[i+m-1];
        ll c1 = 0, c2 = 0;
        if (mi<a1) c1 = a1-mi;
        if (a2<ma) c2 = ma-a2;
        chmin(ans, c1+c2);
    }
    cout << ans << endl;
    return 0;
}