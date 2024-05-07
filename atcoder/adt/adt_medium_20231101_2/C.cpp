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
    vector<ll>s(n);
    rep(i,0,n)cin>>s[i];
    vector<bool> v(1001);
    rep(a,1,310)rep(b,1,310){
        ll temp = 4*a*b + 3*a + 3*b;
        if (temp>1000)continue;
        v[temp] = true;
    }
    ll ans = 0;
    rep(i,0,n)if (!v[s[i]]) ans++;
    cout << ans << endl;
    return 0;
}