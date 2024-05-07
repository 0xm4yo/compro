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
const double INF = 1e18+10;

int main()
{
    ll l,x,y,s,d;
    cin>>l>>x>>y>>s>>d;
    ll v1 = x + y;
    ll d1;
    double ans = INF;
    if (d>=s){
        d1 = d-s;
    }else{
        d1 = l-(s-d);
    }
    chmin(ans, (double)d1/(double)(x+y));
    if (y-x>0) chmin(ans, (double)(l-d1)/(double)(y-x));
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}