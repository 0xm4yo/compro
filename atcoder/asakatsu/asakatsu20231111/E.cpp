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
    vector<string>s(h);
    rep(i,0,h)cin>>s[i];
    dsu uf(h*w);
    rep(i,0,h)rep(j,0,w){
        if (s[i][j]=='#')continue;
        rep(dh,-1,2)rep(dw,-1,2){
            if (abs(dh)+abs(dw)>1)continue;
            if (0<=i+dh && i+dh<h && 0<=j+dw && j+dw<w){
                if (s[i+dh][j+dw]=='#'){
                    uf.merge(i*w+j, (i+dh)*w+j+dw);
                }
            }
        }
    }
    vector<ll>g(h*w);
    rep(i,0,h)rep(j,0,w){
        if (s[i][j]=='#') g[i*w+j] = 1;
    }
    ll ans = 0;
    for (auto v: uf.groups()){
        ll cnt = 0;
        for (auto x: v){
            if (g[x]) cnt++;
        }
        ans += cnt * (v.size()-cnt);
    }
    cout << ans << endl;
    return 0;
}