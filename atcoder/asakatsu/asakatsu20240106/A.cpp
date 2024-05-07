#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YesNo(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)1e18+10;

int main()
{
    ll n;
    cin>>n;
    vector<ll> a,p(n);
    rep(i,0,n)a.push_back(i+1);
    rep(i,0,n)cin>>p[i];
    bool flag = false;
    rep(i,0,n)rep(j,i+1,n){
        swap(p[i],p[j]);
        if (a==p) flag = true;
        swap(p[i],p[j]);
    }
    if (a==p) flag = true;
    YesNo(flag);
    return 0;
}