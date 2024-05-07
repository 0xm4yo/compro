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
    double ans = -1;
    auto f = [&](ll a, ll b){
        return sqrt((x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]));
    };
    rep(i,0,n)rep(j,i+1,n){
        chmax(ans, f(i,j));
    }
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}