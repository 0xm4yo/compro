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
const ll INF = numeric_limits<ll>::max();

int main()
{
    ll n,x;
    cin>>n>>x;
    vector<ll>a(n),b(n);
    rep(i,0,n)cin>>a[i]>>b[i];
    ll ans = INF;
    ll now = 0LL;
    rep(i,0,n){
        if (x<i+1) break;
        now += a[i] + b[i];
        chmin(ans, now + (x-(i+1LL))*b[i]);
    }
    cout << ans << endl;
    return 0;
}