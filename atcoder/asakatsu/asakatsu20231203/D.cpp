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
    ll h,w;
    cin>>h>>w;
    ll sh,sw,gh,gw;
    cin>>sh>>sw>>gh>>gw;
    sh--;sw--;gh--;gw--;
    vector<string> s(h);
    rep(i,0,h)cin>>s[i];
    queue<pair<ll,ll>> q;
    vector<ll> dh = {0,0,1,-1}, dw = {1,-1,0,0};
    q.push({sh,sw});
    vector<vector<ll>> v(h,vector<ll>(w,INF));
    v[sh][sw] = 0;
    while(!q.empty()){
        auto [nh,nw] = q.front(); q.pop();
        rep(i,0,4){
            ll nxh = nh + dh[i];
            ll nxw = nw + dw[i];
            if (v[nxh][nxw]!=INF) continue;
            if (s[nxh][nxw]=='.'){
                v[nxh][nxw] = v[nh][nw] + 1;
                q.push({nxh,nxw});
            }
        }
    }
    cout << v[gh][gw] << endl;
    return 0;
}