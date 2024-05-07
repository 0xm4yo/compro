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
    ll n;
    cin>>n;
    vector<vector<ll>>g(n);
    rep(i,0,n-1){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    vector<bool>v(n);
    vector<ll>dp(n),cnt(n);
    function<pair<ll,ll>(ll)> dfs = [&](ll now){
        v[now] = true;
        ll res = 0;
        ll c = 0;
        for (auto nex: g[now]){
            if (v[nex])continue;
            auto temp = dfs(nex);
            res += temp.first + temp.second;
            c += temp.second;
        }
        c++;
        cnt[now] = c;
        dp[now] = res;
        return make_pair(res,c);
    };
    dfs(0);
    
    rep(i,0,n)v[i]=false;
    function<void(ll,ll)> dfs2 = [&](ll now, ll pre){
        v[now] = true;
        if (pre!=-1){
            dp[now] = dp[pre] + n - cnt[now]*2;
        }
        for (auto nex: g[now]){
            if (v[nex]) continue;
            dfs2(nex, now);
        }
        return;
    };    
    dfs2(0,-1);
    rep(i,0,n){
        cout << dp[i] << endl;
    }

    return 0;
}