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
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)a[i]--;
    vector<bool> v(n);

    bool flag = false;
    ll pos = -1;
    vector<ll> ans;
    function<void(ll)> dfs = [&](ll now){
        v[now] = true;
        ll nex = a[now];
        if (v[nex]){
            flag = true;
            pos = nex;
        }else{
            dfs(nex);
        }
        if (flag) ans.push_back(now);
        if (now==pos)flag = false;
        v[now] = false;
    };

    rep(i,0,n){
        if (ans.size())break;
        dfs(i);
    }
    reverse(all(ans));
    cout << ans.size() << endl;
    for (auto x: ans) cout << x+1 << endl;
    return 0;
}