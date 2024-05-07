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

    auto f = [&](double x){
        double tot = 0.0;
        rep(i,0,n){
            tot += x;
            tot += (double)a[i];
            tot -= min(x*2.0, (double)a[i]);
        }
        return tot;
    };

    double l = 0.0;
    double r = 10000000010.0; 
    while(r-l>0.0000001){
        double c1 = (l*2.0+r)/3.0;
        double c2 = (l+r*2.0)/3.0;
        if (f(c1)<f(c2)){
            r = c2;
        }else{
            l = c1;
        }
    }
    double ans = f(l)/(double)n;
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}