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
    ll x,y;
    cin>>x>>y;
    vector<ll>a(3);
    rep(i,0,3) cin>>a[i];

    bool flag = false;
    ll temp = 0;
    rep(i,0,3){
        temp += (a[i]+y-1)/y;
    }
    if (temp<=x) flag = true;
    
    rep(i,0,3){
        ll h = (a[i]+x-1)/x;
        ll rem = y - h;
        if (rem<=0) continue;
        temp = 0;
        rep(j,0,3){
            if (i==j) continue;
            temp += (a[j]+rem-1)/rem;
        }
        if (temp<=x) flag = true;
    }

    swap(x,y);
    temp = 0;
    rep(i,0,3){
        temp += (a[i]+y-1)/y;
    }
    if (temp<=x) flag = true;
    
    rep(i,0,3){
        ll h = (a[i]+x-1)/x;
        ll rem = y - h;
        if (rem<=0) continue;
        temp = 0;
        rep(j,0,3){
            if (i==j) continue;
            temp += (a[j]+rem-1)/rem;
        }
        if (temp<=x) flag = true;
    }

    YesNo(flag);

    return 0;
}