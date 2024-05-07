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
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> g(n+1);
    rep(i,0,m){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll>dp1(n+1,INF), dp2(n+1,INF);
    queue<ll> q;
    q.push(1);
    dp1[1] = 0;
    while(!q.empty()){
        ll now = q.front(); q.pop();
        for (auto nex: g[now]){
            if (dp1[nex]!=INF)continue;
            dp1[nex] = dp1[now] + 1;
            if (nex!=0) q.push(nex);
        }
    }
    dp2[n] = 0;
    q.push(n);
    while(!q.empty()){
        ll now = q.front(); q.pop();
        for (auto nex: g[now]){
            if (dp2[nex]!=INF)continue;
            dp2[nex] = dp2[now] + 1;
            if (nex!=0) q.push(nex);
        }
    }
    rep(i,1,n+1){
        ll ans = INF;
        chmin(ans, dp1[n]);
        chmin(ans, dp1[0]+dp2[i]);
        chmin(ans, dp1[i]+dp2[0]);
        chmin(ans, dp1[0]+dp2[0]);
        if (ans==INF) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}