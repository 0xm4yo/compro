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
    ll n,x,y,z;
    cin>>n>>x>>y>>z;
    vector<ll>a(n),b(n);
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)cin>>b[i];
    vector<pair<ll,ll>>arrx,arry,arrz;
    rep(i,0,n){
        arrx.push_back({-a[i],i});
        arry.push_back({-b[i],i});
        arrz.push_back({-(a[i]+b[i]),i});
    }
    sort(all(arrx));
    sort(all(arry));
    sort(all(arrz));
    vector<bool>v(n);
    ll pos = 0;
    while(x){
        auto [s,idx] = arrx[pos];
        if (!v[idx]){ x--; v[idx]=true; }
        pos++;
    }
    pos = 0;
    while(y){
        auto [s,idx] = arry[pos];
        if (!v[idx]){ y--; v[idx]=true; }
        pos++;
    }
    pos = 0;
    while(z){
        auto [s,idx] = arrz[pos];
        if (!v[idx]){ z--; v[idx]=true; }
        pos++;
    }
    rep(i,0,n){
        if (v[i]) cout << i+1 << endl;
    }
    return 0;
}