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
const ll INF = numeric_limits<ll>::max();

int main()
{
    ll n;
    cin>>n;
    vector<vector<ll>>g(n);
    vector<ll>indeg(n);
    rep(i,0,n-1){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        indeg[a]++;
        indeg[b]++;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll cnt = 0;
    rep(i,0,n) if(indeg[i]==1) cnt++;
    bool flag = true;
    if (cnt != n-1) flag = false;
    ll d = -1;
    rep(i,0,n)if(indeg[i]!=1) d=indeg[i];
    if (d!=n-1) flag = false;
    YesNo(flag); 
    return 0;
}