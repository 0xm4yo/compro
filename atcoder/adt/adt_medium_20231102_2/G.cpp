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
    vector<vector<ll>> g(n);
    rep(i,0,n-1){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i,0,n) sort(all(g[i]));
    vector<bool> v(n);
    vector<ll>ans;
    function<void(ll)> dfs = [&](ll now){
        v[now] = true;
        for (auto nex: g[now]){
            if (v[nex])continue;
            ans.push_back(now);
            dfs(nex);
        }
        ans.push_back(now);
    };
    dfs(0);
    for (auto a: ans){
        cout << a+1 << endl;
    }
    return 0;
}