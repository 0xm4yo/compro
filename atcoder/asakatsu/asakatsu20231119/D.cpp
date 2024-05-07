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
    vector<vector<ll>> g(2*n, vector<ll>(2*n));
    rep(i,0,2*n-1){
        rep(j,i+1,2*n){
            cin>>g[i][j];
        }
    }
    ll ans = 0;
    function<void(ll,ll)> f = [&](ll s, ll now){
        if (s==(1<<(2*n))-1){
            chmax(ans, now);
            return ;
        };
        ll st = 0;
        rep(i,0,2*n){
            if (s&(1LL<<i)) continue;
            st = i;
            break;
        }
        rep(i,st+1,2*n){
            ll res = 0;
            if (s&(1LL<<i)) continue;
            f(s+(1LL<<st)+(1LL<<i), now^g[st][i]);
        }
        return ;
    };

    f(0, 0);
    cout << ans << endl;
    return 0;
}