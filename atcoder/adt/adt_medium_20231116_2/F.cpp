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

using P = pair<ll,ll>;

int main()
{
    ll ax,ay,bx,by,cx,cy,dx,dy;
    cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;

    auto f = [](P i, P j){
        auto [ix, iy] = i;
        auto [jx, jy] = j;
        ll z = ix*jy - jx*iy;
        return z < 0;
    };

    bool flag = true;
    if (f({bx-ax,by-ay}, {dx-ax,dy-ay})) flag = false;
    if (f({cx-bx,cy-by}, {ax-bx,ay-by})) flag = false;
    if (f({dx-cx,dy-cy}, {bx-cx,by-cy})) flag = false;
    if (f({ax-dx,ay-dy}, {cx-dx,cy-dy})) flag = false;
    YesNo(flag);
    return 0;
}