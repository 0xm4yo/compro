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
    vector<string> s(h);
    rep(i,0,h)cin>>s[i];
    ll ans = 0;
    rep(i,0,h-1)rep(j,0,w-1){
        ll cnt = 0;
        rep(k,0,2)rep(l,0,2){
            if (s[i+k][j+l]=='#') cnt++;
        }
        if (cnt==0) continue;
        if (cnt==1 || cnt==3){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}