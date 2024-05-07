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
    ll k;
    cin>>k;
    ll cnt1 = 0;
    ll cnt2 = 0;
    ll cnt3 = 0;
    rep(a,1,k+1){
        rep(b,a,k+1){
            if (a*b>k)break;
            ll c = k/(a*b);
            if (c-b<0) break;
            if (a==b) cnt3++;
            else cnt2++;
            if (a==b) cnt2 += c-b;
            else cnt1 += c-b;
        }
    }
    ll ans = cnt1*6 + cnt2*3 + cnt3;
    cout << ans << endl;
    return 0;
}