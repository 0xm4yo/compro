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
    ll n,l,w;
    cin>>n>>l>>w;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    ll now = 0;
    ll ans = 0;
    ll pos = 0;
    while(pos<n){
        if (a[pos]<=now){
            now = max(now, a[pos]+w);
            pos++;
            continue;
        }
        ll d = a[pos] - now;
        ans += (d+w-1)/w;
        now += w * ((d+w-1)/w);
    }
    ll rem = l - now;
    ans += (rem+w-1)/w;
    cout << ans << endl;
    return 0;
}