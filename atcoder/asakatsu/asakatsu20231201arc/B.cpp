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
    ll h,w,C,q;
    cin>>h>>w>>C>>q;
    vector<ll>t(q),n(q),c(q);
    rep(i,0,q)cin>>t[i]>>n[i]>>c[i];
    ll cnth = 0;
    ll cntw = 0;
    map<ll,bool>mph, mpw;
    map<ll,ll>ans;
    rrep(i,q-1,0){
        if (t[i]==1){
            if (mpw[n[i]]) continue;
            mpw[n[i]] = true;
            ans[c[i]] += w - cnth;
            cntw++;
        }else{
            if (mph[n[i]]) continue;
            mph[n[i]] = true;
            ans[c[i]] += h - cntw;
            cnth++;
        }
    }
    rep(i,1,C+1){
        cout << ans[i] << endl;
    }
    return 0;
}