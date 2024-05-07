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
    ll n,q;
    cin>>n>>q;
    vector<set<ll>> g(n);
    ll ans = n;
    rep(i,0,q){
        ll c,u,v;
        cin>>c;
        if (c==1){
            cin>>u>>v;
            u--;v--;
            if (g[u].size()==0) ans--;
            if (g[v].size()==0) ans--;
            g[u].insert(v);
            g[v].insert(u);
        }else{
            cin>>u;
            u--;
            if (g[u].size()>0) ans++;
            for (auto x: g[u]){
                g[x].erase(u);
                if (g[x].size()==0) ans++;
            }
            g[u] = set<ll>();
        }
        cout << ans << endl;
    }    
    
    return 0;
}