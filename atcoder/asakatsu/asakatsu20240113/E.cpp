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
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,0,n)cin>>a[i];
    ll ans = 0;
    rep(i,0,n){
        ll temp = (n-i)/2;
        ans += temp * (1+ temp);
        if ((n-i)%2==0){
            ans -= temp;            
        }       
    }
    vector<vector<ll>> g(n+1);
    rep(i,0,n){
        g[a[i]].push_back(i);
    }

    rep(i,1,n+1){
        ll sz = g[i].size();
        if (sz<=1) continue;
        ll l = 0;
        ll r = sz-1;
        ll temp = 0;
        while(r-l>0){
            ll la = g[i][l];
            ll ra = g[i][r];
            if (n-ra-1 <= la){
                temp += (n-ra)*(sz-1);
                sz--;
                r--;
            }else{
                temp += (la+1) * (sz-1);
                sz--;
                l++;
            }
        }
        ans -= temp;
    }
    cout << ans << endl;

    return 0;
}
