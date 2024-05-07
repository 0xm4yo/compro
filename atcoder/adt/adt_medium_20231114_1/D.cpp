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
    vector<ll>p(n),c(n);
    vector<bitset<200>>f(n);
    rep(i,0,n){
        cin>>p[i]>>c[i];
        rep(j,0,c[i]){
            ll ff;
            cin>>ff;
            ff--;
            f[i].set(ff);
        }
    }
    bool flag = false;
    rep(i,0,n){
        auto f1 = f[i];
        rep(j,0,n){
            if (i==j)continue;
            if (p[i]<p[j])continue;
            auto f2 = f[j];
            if ((f1&f2)!=f1)continue;
            if (p[i]>p[j])flag = true;
            if (f1.count()<f2.count())flag = true;
        }
    }
    YesNo(flag);
    return 0;
}