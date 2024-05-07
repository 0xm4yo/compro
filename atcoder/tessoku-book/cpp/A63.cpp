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
    vector<vector<ll>>g(n);
    rep(i,0,m){
        ll a, b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<ll> q;
    vector<ll>v(n,-1);
    q.push(0);
    v[0]=0;
    while (!q.empty()){
        ll now = q.front();q.pop();
        for(auto nex:g[now]){
            if (v[nex]!=-1)continue;
            v[nex]=v[now]+1;
            q.push(nex);
        }
    }
    rep(i,0,n){
        cout << v[i] << endl;
    }
    return 0;
}