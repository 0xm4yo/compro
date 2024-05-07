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
    ll n,l,r;
    cin>>n>>l>>r;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    rep(i,0,n){
        if (l<=a[i] && a[i]<=r){
            cout << a[i] << endl;
            continue;
        }
        ll p = abs(l-a[i]);
        ll q = abs(r-a[i]);
        ll z = min(p,q);
        ll ans = 0;
        if (abs(l-a[i])<=z){
            ans = l;
        }else{
            ans = r;
        }
        cout << ans << endl;
    }
    return 0;
}