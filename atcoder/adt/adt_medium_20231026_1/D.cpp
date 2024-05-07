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
const ll INF = (ll)3e15;

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>a(m), par(n);
    rep(i,0,m)cin>>a[i];
    rep(i,0,n)par[i]=i;
    rep(i,0,m){
        par[a[i]-1] = a[i];
    }
    ll l = 0;
    rep(r,0,n){
        if (par[r]==r){
            rrep(i,r,l){
                cout << i+1 << endl;
            }
            l = r+1;
        }
    }

    return 0;
}
