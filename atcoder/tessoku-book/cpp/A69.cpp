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
    ll n;
    cin>>n;
    vector<string>s(n);
    rep(i,0,n)cin>>s[i];
    mf_graph<ll> g(n*2+2);
    rep(i,0,n)rep(j,0,n){
        if (s[i][j] == '.')continue;
        g.add_edge(i,n+j,1);
    }
    rep(i,0,n){
        g.add_edge(2*n,i,1);
        g.add_edge(i+n,2*n+1,1);
    }
    cout << g.flow(2*n,2*n+1) << endl;

    return 0;
}