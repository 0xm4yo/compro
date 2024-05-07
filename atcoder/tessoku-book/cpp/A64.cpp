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
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>g(n);
    rep(i,0,m){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    priority_queue<pair<ll,ll>> hq;
    hq.push({-0,0});
    vector<ll>v(n,-1);
    while(!hq.empty()){
        auto [cost, now] = hq.top();hq.pop();
        cost *= -1;
        if (v[now]!=-1)continue;
        v[now] = cost;
        for(auto [nex,c]: g[now]){
            if(v[nex]!=-1)continue;
            hq.push({-(cost+c),nex});
        }
    }
    rep(i,0,n){
        cout << v[i] << endl;
    }
    return 0;
}