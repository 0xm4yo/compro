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

ll op1(ll a, ll b){ return min(a,b); }
ll e1(){ return INF; }

ll op2(ll a, ll b){ return a+b; }
ll e2(){ return 0LL; }

int main()
{
    ll n;
    cin>>n;
    vector<vector<tuple<ll,ll,ll>>> g(n);
    rep(i,0,n-1){
        ll u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        g[u].push_back({v,w,i});
        g[v].push_back({u,w,i});
    }

    vector<ll> arr, in(n);
    vector<ll> ein(n-1), eout(n-1), init(n-1);
    function<void(ll,ll)> dfs = [&](ll now, ll pre){
        in[now] = arr.size();
        arr.push_back(now);
        for (auto [nex,cost,idx]: g[now]){
            if (nex==pre) continue;
            init[idx] = cost;
            ein[idx] = arr.size()-1;
            dfs(nex, now);
            eout[idx] = arr.size()-1;
            arr.push_back(now);
        }
    };

    dfs(0,-1);

    segtree<ll,op1,e1> rmq(arr.size());
    rep(i,0,arr.size()) rmq.set(i, in[arr[i]]);

    segtree<ll,op2,e2> rsq(arr.size());
    rep(i,0,n-1){
        rsq.set(ein[i], init[i]);
        rsq.set(eout[i], -init[i]);
    }   

    ll q;
    cin>>q;
    while(q){
        q--;
        ll c,a,b;
        cin>>c>>a>>b;
        if (c==1){
            a--;
            rsq.set(ein[a], b);
            rsq.set(eout[a], -b);
        }else{
            a--; b--;
            ll l = in[a];
            ll r = in[b];
            if (l>r) swap(l,r);
            ll par = rmq.prod(l,r+1);
            ll d = rsq.prod(0, l) + rsq.prod(0, r) - rsq.prod(0, par)*2;
            cout << d << endl;
        } 
    }
    return 0;
}