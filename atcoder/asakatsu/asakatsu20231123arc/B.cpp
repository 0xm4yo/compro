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
    vector<ll>t(n);
    rep(i,0,n)cin>>t[i];
    vector<ll> ctz(41);
    rep(i,0,41){
        ctz[i] = 1LL<<i;
    }
    ll now = 0;
    rep(i,0,n){
        ll l = -1;
        ll r = INF;
        r >>= t[i]+1;
        while(r-l>1){
            ll mid = (l+r)/2LL;
            ll temp = (mid<<(t[i]+1)) + ctz[t[i]];
            if (temp<=now){
                l = mid;
            }else{
                r = mid;
            }
        }
        now = (r<<(t[i]+1)) + ctz[t[i]];
        // cout << now << endl;
    }
    cout << now << endl;
    return 0;
}