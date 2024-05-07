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
    vector<ll>r(n);
    rep(i,0,n)cin>>r[i];
    sort(all(r));
    reverse(all(r));
    double ans = 0.0;
    rep(i,0,n){
        if (i%2){
            ans -= pi * r[i] * r[i];
        }else{
            ans += pi * r[i] * r[i];
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}