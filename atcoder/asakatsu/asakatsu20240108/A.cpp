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
    ll ans = INF;
    rep(a,1,n){
        ll b = n-a;
        if (a>b) break;
        ll temp = 0;
        string aa = to_string(a);
        string bb = to_string(b);
        rep(i,0,aa.size()) temp += aa[i] - '0';
        rep(i,0,bb.size()) temp += bb[i] - '0';
        chmin(ans, temp);
    }
    cout << ans << endl;
    return 0;
}