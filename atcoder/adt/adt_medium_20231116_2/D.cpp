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
    ll n,k;
    cin>>n>>k;
    vector<ll>a(k);
    rep(i,0,k)cin>>a[i];
    rep(i,0,k)a[i]--;
    vector<ll>x(n),y(n);
    rep(i,0,n)cin>>x[i]>>y[i];

    auto f = [&](ll aa, ll b, double rad){
        ll xa = x[aa];
        ll ya = y[aa];
        ll xb = x[b];
        ll yb = y[b];
        ll dis = (xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
        if (dis<rad) return true;
        else return false;
    };

    ll ans = 0;
    rep(i,0,n){
        ll dis = INF;
        for (auto j: a){
            chmin(dis, (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
        }
        chmax(ans, dis);
    }

    cout << fixed << setprecision(10) << sqrt(ans) << endl;
    return 0;
}