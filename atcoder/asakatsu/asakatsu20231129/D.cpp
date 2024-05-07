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
    vector<ll> a(m),b(m);
    rep(i,0,m)cin>>a[i]>>b[i];
    rep(i,0,m){ a[i]--; b[i]--; } 
    ll ans = 0;
    rep(i,0,m){
        dsu uf(n);
        rep(j,0,m){
            if (i==j) continue;
            uf.merge(a[j],b[j]);
        }
        if (uf.groups().size()>1) ans++;
    }
    cout << ans << endl;
    return 0;
}