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
const ll INF = (ll)1e15;

int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,1,n)cin>>a[i];
    vector<vector<ll>>to(n);
    rep(i,1,n){
        to[a[i]-1].push_back(i);
    }
    vector<ll> ans(n);
    function<ll(ll)> dfs = [&](ll now){
        ll res = 0;
        for (auto nex: to[now]){
            res += dfs(nex);
        }
        ans[now] = res;
        return res+1;
    };
    dfs(0);
    rep(i,0,n){
        cout << ans[i] << endl;
    }
    
    return 0;
}