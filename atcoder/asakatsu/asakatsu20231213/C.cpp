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
const ll INF = (ll)8e18+10;

int main()
{
    ll n,x;
    cin>>n>>x;
    ll ans = INF;
    ll tot = 0;
    rep(i,0,n){
        ll a,b;
        cin>>a>>b;
        ll temp = tot;
        temp += a + b;
        tot += a + b;
        x--; 
        if (x<=0){
            chmin(ans, temp);
            break;
        }
        temp += x*b;
        chmin(ans, temp);
    }
    cout << ans << endl;
    return 0;
}