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
    vector<string>s(n);
    rep(i,0,n)cin>>s[i];
    ll ans = 0;
    rep(i,0,n)rep(j,i+1,n){
        vector<bool> f(m);
        rep(k,0,m){
            if (s[i][k]=='o')f[k]=true;
            if (s[j][k]=='o')f[k]=true;
        }
        bool ac = true;
        rep(k,0,m)if(!f[k])ac=false;
        if (ac)ans++;
    }
    cout << ans << endl;
    return 0;
}