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
    vector<vector<tuple<ll,ll,ll>>> g(n);
    rep(i,0,m){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        a--;b--;
        g[a].push_back({b,c,d});
        g[b].push_back({a,c,d});
    }
    priority_queue<tuple<ll,ll,ll>> hq;
    hq.push({-0,0,0});
    vector<ll> v(n,INF), cnt(n,-1);
    while (!hq.empty()){
        auto [cost, now, cc] = hq.top(); hq.pop();
        cost *= -1;
        if (v[now]!=INF){
            if (v[now]==cost){
                chmax(cnt[now], cc);
            }
            continue;
        }
        v[now] = cost;
        chmax(cnt[now],cc);
        for (auto [nex,c,d]: g[now]){
            if (v[nex]!=INF)continue;
            hq.push({-(cost+c), nex, cnt[now]+d});
        }
    }
    cout << v[n-1] << endl;
    cout << cnt[n-1] << endl;
    return 0;
}