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
    vector<vector<ll>>g(n);
    dsu uf(n);
    rep(i,0,m){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
        uf.merge(a,b);
    }

    function<ll(ll,vector<ll>)> dfs = [&](ll now, vector<ll> v){
        vector<bool> col(3);
        for (auto nex: g[now]){
            if (v[nex]!=-1) col[v[nex]] = true;
        }

        vector<ll> st;
        vector<bool> vis(n);
        function<void(ll)> f = [&](ll a){
            vis[a] = true;
            for (auto b: g[a]){
                if (v[b]!=-1) continue;
                if (vis[b]) continue;
                if (a==now) st.push_back(b);
                f(b);
            }
        };

        f(now);

        ll res = 0;
        rep(i,0,3){
            if (col[i]) continue;
            ll temp = 1;
            for (auto nex: st){
                if (v[nex]!=-1) continue;
                v[now] = i;
                temp *= dfs(nex, v);
            }
            res += temp;
        }
        return res;
    };

    vector<ll> st;
    for (auto vec: uf.groups()){
        ll ld = uf.leader(vec[0]);
        st.push_back(ld);
    }

    ll ans = 1;
    for (auto s: st){
        vector<ll> init(n, -1);
        if (g[s].size()) ans *= dfs(s, init);
        else ans *= 3;
    }
    cout << ans << endl;
    return 0;
}