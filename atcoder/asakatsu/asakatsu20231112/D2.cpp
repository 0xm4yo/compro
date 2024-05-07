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
    ll n,c;
    cin>>n>>c;
    map<ll,ll> mp;
    rep(i,0,n){
        ll a,b,c;
        cin>>a>>b>>c;
        mp[a] += c;
        mp[b+1] -= c; 
    }
    ll ans = 0;
    ll s = 0;
    ll pre = 0;
    for (auto [t, cost]: mp){
        ans += min(s,c) * (t-pre);
        s += cost;
        pre = t;
    }
    cout << ans << endl;
    return 0;
}