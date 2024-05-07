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
    ll n1,n2,m;
    cin>>n1>>n2>>m;
    vector<vector<ll>> g(n1+n2);
    rep(i,0,m){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<ll> q;
    q.push(0);
    vector<ll>v(n1+n2,-1);
    v[0] = 0;
    while (!q.empty()){
        ll now = q.front(); q.pop();
        for (auto nex: g[now]){
            if (v[nex]!=-1)continue;
            v[nex]=v[now]+1;
            q.push(nex);
        }
    }
    q.push(n1+n2-1);
    v[n1+n2-1] = 0;
    while (!q.empty()){
        ll now = q.front(); q.pop();
        for (auto nex: g[now]){
            if (v[nex]!=-1)continue;
            v[nex]=v[now]+1;
            q.push(nex);
        }
    }

    ll l = 0;
    rep(i,0,n1) chmax(l,v[i]);
    ll r = 0;
    rep(i,n1,n1+n2) chmax(r,v[i]);
    cout << l + r + 1 << endl;
    
    return 0;
}