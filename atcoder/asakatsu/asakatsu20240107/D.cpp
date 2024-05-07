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
    ll ans = INF;
    rep(i,0,110){
        ll pos = 0;
        ll cnt = 0;
        ll now = 0;
        ll temp = 0;
        while(pos<n){
            cnt++;
            now += a[pos];
            pos++;
            if (cnt*i==now){
                temp += cnt-1;
                cnt = 0;
                now = 0;
            }
        }
        if (pos!=n) continue;
        if (cnt!=0) continue;
        chmin(ans, temp);
    }
    if (ans==INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}