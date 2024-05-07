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
    vector<ll> x(n),y(n);
    set<pair<ll,ll>> st;
    rep(i,0,n)cin>>x[i]>>y[i];
    rep(i,0,n)st.insert({x[i],y[i]});
    ll ans = 0;
    rep(i,0,n)rep(j,0,n){
        if(i==j)continue;
        if (x[i]>=x[j])continue;
        if (y[i]<=y[j])continue;
        bool flag = true;
        if (st.find({x[j],y[i]}) == st.end()) flag = false;
        if (st.find({x[i],y[j]}) == st.end()) flag = false;
        if (flag) ans++;
    }
    cout << ans << endl;

    return 0;
}