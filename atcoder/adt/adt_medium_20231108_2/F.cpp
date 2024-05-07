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
    ll n,x,y;
    cin>>n>>x>>y;
    x--;y--;
    vector<vector<ll>>g(n);
    rep(i,0,n-1){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll>ans;
    bool flag = false;
    vector<bool>v(n);
    function<void(ll)> dfs = [&](ll now){
        v[now] = true;
        if (now == y) flag = true;
        for (auto nex: g[now]){
            if (v[nex])continue;
            if (flag)continue;
            dfs(nex);
        }
        if (flag) ans.push_back(now+1);
        return ;
    };

    dfs(x);
    reverse(all(ans));
    for (auto a: ans) cout << a << endl;
    return 0;
}