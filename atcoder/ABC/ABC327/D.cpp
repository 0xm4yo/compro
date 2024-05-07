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
    ll n,m;
    cin>>n>>m;
    vector<ll>a(m),b(m);
    rep(i,0,m)cin>>a[i];
    rep(i,0,m)cin>>b[i];
    vector<vector<ll>>g(n+1);
    bool flag = true;
    rep(i,0,m){
        g[a[i]-1].push_back(b[i]-1);
        g[b[i]-1].push_back(a[i]-1);
    }
    vector<ll> v(n,-1);
    function<void(ll,ll)> dfs = [&](ll now, ll d){
        v[now] = d;
        for (auto nex: g[now]){
            if (v[nex]!=-1){
                ll dif = abs(v[nex]-v[now]);
                if (dif>=2 && dif%2==0) flag = false;
                continue;
            }
            dfs(nex, d+1);
        }
    };
    rep(i,0,n){
        if (v[i]==-1) dfs(i,0);
    }
    rep(i,0,m) if (a[i]==b[i]) flag = false;
    YesNo(flag);
    return 0;
}