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
    ll sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    string ans = "";
    ans += 'L';
    rep(i,0,ty+1-sy) ans += 'U';
    rep(i,0,tx+1-sx) ans += 'R';
    ans += 'D';

    ans += 'R';
    rep(i,0,ty+1-sy) ans += 'D';
    rep(i,0,tx+1-sx) ans += 'L';
    ans += 'U';

    rep(i,0,ty-sy) ans += 'U';
    rep(i,0,tx-sx) ans += 'R';

    rep(i,0,ty-sy) ans += 'D';
    rep(i,0,tx-sx) ans += 'L';

    cout << ans << endl;

    return 0;
}