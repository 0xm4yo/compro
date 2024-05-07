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
    ll h1,h2,h3,w1,w2,w3;
    cin>>h1>>h2>>h3>>w1>>w2>>w3;
    ll ans = 0;
    rep(i,1,31){
        ll g[3][3];
        rep(j,1,31){
            if (i+j>=h1)break;
            rep(k,1,31){
                if (i+k>=w1)break;
                rep(l,1,31){
                    if (j+l>=w2)break;
                    if (k+l>=h2)break;
                    ll a = h1-i-j;
                    ll b = h2-k-l;
                    ll c = w3-a-b;
                    if (c<=0)continue;
                    ll x = w1-i-k;
                    ll y = w2-j-l;
                    ll z = h3-x-y;
                    if (z<=0)continue;
                    if (z==c)ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}