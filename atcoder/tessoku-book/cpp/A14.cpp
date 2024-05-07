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
const ll INF = (ll)1e15;

int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n),b(n),c(n),d(n);
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)cin>>b[i];
    rep(i,0,n)cin>>c[i];
    rep(i,0,n)cin>>d[i];
    vector<ll>ab,cd;
    rep(i,0,n)rep(j,0,n){
        ab.push_back(a[i]+b[j]);
        cd.push_back(c[i]+d[j]);
    }
    map<ll,ll> mp;
    for(auto x: cd){
        mp[x]++;
    }
    ll ans = 0;
    for (auto x: ab){
        if (mp.find(k-x) == mp.end())continue;
        else ans += mp[k-x];
    }
    YesNo(ans);
    return 0;
}