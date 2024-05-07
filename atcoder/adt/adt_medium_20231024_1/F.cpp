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
const ll INF = numeric_limits<ll>::max();

int main()
{
    vector<string> s(9);
    rep(i,0,9)cin>>s[i];
    vector<pair<ll,ll>> arr;
    rep(i,0,9)rep(j,0,9){
        if (s[i][j]=='#')arr.push_back({i,j});
    }
    ll sz = arr.size();
    ll ans = 0;
    rep(i,0,sz)rep(j,i+1,sz)rep(k,j+1,sz)rep(l,k+1,sz){
        auto [ax,ay]=arr[i];
        auto [bx,by]=arr[j];
        auto [cx,cy]=arr[k];
        auto [dx,dy]=arr[l];
        auto [abx,aby] = make_pair(bx-ax,by-ay);
        auto [acx,acy] = make_pair(cx-ax,cy-ay);
        ll abac = abx*acx + aby*acy;
        auto [dbx,dby] = make_pair(bx-dx,by-dy);
        auto [dcx,dcy] = make_pair(cx-dx,cy-dy);
        ll dbdc = dbx*dcx + dby*dcy;
        if (abac==0 && dbdc==0){
            double ab = sqrt(abx*abx+aby*aby);
            double ac = sqrt(acx*acx+acy*acy);
            double db = sqrt(dbx*dbx+dby*dby);
            double dc = sqrt(dcx*dcx+dcy*dcy);
            if (ab==ac && ac==db && db==dc) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}