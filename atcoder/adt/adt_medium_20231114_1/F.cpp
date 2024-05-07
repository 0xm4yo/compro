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
    vector<ll>a(m);
    rep(i,0,m)cin>>a[i];
    rep(i,1,n+1){
        auto itr = lower_bound(all(a), i);
        if (*itr==i) cout << 0 << endl;
        else if (*itr>i) cout << *itr-i << endl;
        else itr++, cout << *itr-i-1 << endl;
    }
    return 0;
}
