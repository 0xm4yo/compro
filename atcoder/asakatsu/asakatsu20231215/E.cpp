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
    ll sh,sw,gh,gw;
    cin>>sh>>sw>>gh>>gw;
    sh--;sw--;gh--;gw--;
    vector<string>s(n);
    rep(i,0,n)cin>>s[i];
    deque<tuple<ll,ll,ll,ll>> q;
    vector<vector<vector<ll>>> v(n, vector<vector<ll>>(n, vector<ll>(4,INF)));
    rep(i,0,4) q.push_back({0,sh,sw,i});
    vector<ll> dh = {1,1,-1,-1};
    vector<ll> dw = {1,-1,1,-1};
    while(!q.empty()){
        auto [dis,nh,nw,mode] = q.front(); q.pop_front();
        if (v[nh][nw][mode]!=INF) continue;
        v[nh][nw][mode] = dis;
        rep(i,0,4){
            ll nxh = nh + dh[i];
            ll nxw = nw + dw[i];
            if (nxh<0 || nxh>=n || nxw<0 || nxw>=n) continue;
            if (s[nxh][nxw]=='#') continue;
            if (mode == i){
                q.push_front({dis, nxh, nxw, i});
            }else{
                q.push_back({dis+1, nxh, nxw, i});
            }
        }
    }
    ll ans = INF;
    rep(i,0,4) chmin(ans, v[gh][gw][i]);
    if (ans==INF){
        cout << -1 << endl;
    }else{
        cout << ans+1 << endl;
    }
    return 0;
}