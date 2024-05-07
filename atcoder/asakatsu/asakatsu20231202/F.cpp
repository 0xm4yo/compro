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
    rep(i,1,n){
        ll p;
        cin>>p;
        g[i].push_back(p);
        g[p].push_back(i);
    }
    vector<ll> cnt(n);
    function<ll(ll,ll)> dfs = [&](ll now, ll pre){
        ll res = 1;
        for (auto nex: g[now]){
            if (nex==pre)continue;
            res += dfs(nex, now);
        }
        cnt[now] = res;
        return res;
    };

    dfs(0,-1);
    vector<ll>ans(n);
    function<void(ll,ll)> dfs2 = [&](ll now, ll pre){
        ll res = 0;
        for (auto nex: g[now]){
            chmax(res, cnt[nex]);
        }
        ans[now] = res;
        for (auto nex: g[now]){
            if (nex==pre) continue;
            ll temp = cnt[nex];
            cnt[now] -= cnt[nex];
            cnt[nex] = n;
            dfs2(nex, now);
            cnt[now] = n;
            cnt[nex] = temp;
        }
        return ;
    };

    dfs2(0,-1);
    rep(i,0,n){
        cout << ans[i] << endl;
    }
    return 0;
}