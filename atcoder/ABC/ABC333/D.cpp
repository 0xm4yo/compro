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
    vector<ll> indeg(n);
    rep(i,0,n-1){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
        indeg[a]++;
        indeg[b]++;
    }
    queue<ll> q;
    rep(i,0,n){
        if (i==0)continue;
        if (indeg[i]==1) q.push(i);
    }
    vector<ll> v(n,1);
    while(!q.empty()){
        auto now = q.front(); q.pop();
        for (auto nex: g[now]){
            if (nex==0) continue;
            if (indeg[nex]<=1) continue;
            indeg[nex]--;
            v[nex] += v[now];
            if (indeg[nex]==1) q.push(nex);
        }
    }
    ll ans = 1;
    vector<ll>arr;
    for (auto nex: g[0]){
        arr.push_back(v[nex]);
    }
    sort(all(arr));
    rep(i,0,arr.size()-1) ans += arr[i];
    cout << ans << endl;
    return 0;
}