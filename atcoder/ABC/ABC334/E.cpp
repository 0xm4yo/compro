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

using mint = modint998244353;

int main()
{
    ll h,w;
    cin>>h>>w;
    vector<string> s(h);
    rep(i,0,h)cin>>s[i];
    dsu uf(h*w);
    ll r = 0;
    rep(i,0,h)rep(j,0,w){
        if (s[i][j]=='.') {r++; continue;}
        if (i+1<h && s[i+1][j]=='#') uf.merge(i*w+j, (i+1)*w+j);
        if (j+1<w && s[i][j+1]=='#') uf.merge(i*w+j, i*w+j+1);
    }
    ll init = uf.groups().size() - r;
    vector<ll> dh = {0,0,-1,1};
    vector<ll> dw = {1,-1,0,0};
    mint tot = 0;
    rep(i,0,h)rep(j,0,w){
        if (s[i][j]=='#') continue;
        vector<ll> p;
        rep(k,0,4){
            ll nh = i + dh[k];
            ll nw = j + dw[k];
            if (nh<0 || nh>=h || nw<0 || nw>=w) continue;
            if (s[nh][nw] == '#') p.push_back(nh*w+nw); 
        }
        if (p.size()==0){
            tot += init + 1;
            continue;
        }
        set<ll> st;
        for (auto x: p){
            ll ld = uf.leader(x);
            st.insert(ld);
        }
        ll sz = st.size();
        tot += init - sz + 1;
    }
    mint ans = tot/r;
    cout << ans.val() << endl;

    return 0;
}