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
const ll INF = (ll)1e9+10;

int main()
{
    ll a,m,l,r;
    cin>>a>>m>>l>>r;
    auto f = [&](ll mid){
        ll res = 0;
        res += (r-mid)/m;
        res += (mid-l)/m;
        res += 1;
        return res;
    };
    if (a<l){
        ll a2 = a + ((l-a)/m)*m;
        if (a2<l) a2 += m;
        if (l<=a2 && a2<=r){
            ll ans = f(a2);
            cout << ans << endl;
        }else{
            cout << 0 << endl;
        }
    }else if(r<a){
        ll a2 = a - ((a-r)/m)*m;
        if (r<a2) a2-= m;
        if (l<=a2 && a2<=r){
            ll ans = f(a2);
            cout << ans << endl;
        }else{
            cout << 0 << endl;
        }
    }else{
        ll ans = f(a);
        cout << ans << endl;
    }
    return 0;
}