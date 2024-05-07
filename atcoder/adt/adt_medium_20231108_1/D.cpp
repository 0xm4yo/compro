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
    ll n,w;
    cin>>n>>w;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    set<ll>st;
    rep(i,0,n)rep(j,i+1,n)rep(k,j+1,n){
        ll temp = a[i]+a[j]+a[k];
        if (temp<=w) st.insert(temp);
    }
    rep(i,0,n)rep(j,i+1,n){
        ll temp = a[i]+a[j];
        if (temp<=w) st.insert(temp);
    }
    rep(i,0,n){
        ll temp = a[i];
        if (temp<=w) st.insert(temp);
    }
    cout << st.size() << endl;
    return 0;
}