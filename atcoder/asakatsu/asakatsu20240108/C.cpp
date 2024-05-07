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
    ll x,y;
    cin>>x>>y;
    ll ans = INF;
    
    auto f1 = [&](ll xx, ll yy){
        ll res = 0;
        if (yy<xx) return INF;
        else return yy-xx;
    };

    auto f2 = [&](ll xx, ll yy){
        ll res = 1;
        xx *= -1;
        return res + f1(xx, yy);
    };    

    auto f3 = [&](ll xx, ll yy){
        ll res = 2;
        xx *= -1;
        yy *= -1;
        return res + f1(xx, yy);
    };

    auto f4 = [&](ll xx, ll yy){
        ll res = 1;
        yy *= -1;
        return res + f1(xx, yy);
    };

    chmin(ans, f1(x,y));
    chmin(ans, f2(x,y));
    chmin(ans, f3(x,y));
    chmin(ans, f4(x,y));
    cout << ans << endl;

    return 0;
}