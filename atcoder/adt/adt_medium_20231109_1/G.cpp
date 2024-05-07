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
    ll n,m;
    cin>>n>>m;
    ll ans = INF;
    rep(a,1,n+1){
        ll b = (m+a-1)/a;
        if (a>b)break;
        if (b>n)continue;
        chmin(ans, a*b);
    }
    if (ans==INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    
    return 0;
}