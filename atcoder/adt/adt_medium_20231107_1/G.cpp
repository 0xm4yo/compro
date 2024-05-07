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
    vector<ll>indeg(n);
    rep(i,0,m){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        indeg[b]++;
        g[a].push_back(b);
    }
    priority_queue<ll, vector<ll>, greater<ll>> hq;
    rep(i,0,n)if(indeg[i]==0) hq.push(i);
    vector<ll>ans;
    while (!hq.empty()){
        ll now = hq.top(); hq.pop();
        ans.push_back(now+1);
        for (auto nex: g[now]){
            indeg[nex]--;
            if (indeg[nex]==0) hq.push(nex);
        }
    }
    if (ans.size()!=n){
        cout << -1 << endl;
    }else{
        for (auto x: ans) cout << x << endl;
    }
    return 0;
}