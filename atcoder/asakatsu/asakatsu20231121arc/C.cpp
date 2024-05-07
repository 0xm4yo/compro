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
const ll INF = (ll)1e16+10;

int main()
{
    ll n;
    cin>>n;
    ll ans = 0;
    rep(i,1,16){
        string s = "";
        rep(j,0,i){
            s += '1';
        }
        ll l = stoll(s);
        ll r = l+1;
        while(l<=n){
            ans += min(r-1,n)-l+1;
            l *= 10;
            r *= 10;
        }
    }
    cout << ans << endl;
    return 0;
}