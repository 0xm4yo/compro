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
const ll INF = (ll)5e18+10;

int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    
    auto f = [&](ll now){
        vector<ll>cnt(n);
        auto b = a;
        rrep(i,30,0){
            if ((now&(1LL<<i))==0) continue;
            rep(j,0,n){
                if (b[j]&(1LL<<i)) continue;
                b[j] &= ((1LL<<i)-1);
                cnt[j] += (1LL<<i) - b[j];
                b[j] = 0;
            }            
        }
        sort(all(cnt));
        ll tot = 0LL;
        rep(i,0,k) tot+=cnt[i];
        return tot <= m;
    };

    ll ans = 0;
    rrep(i,30,0){
        if (f(ans+(1LL<<i))){
            ans += (1LL<<i);
        }
    }

    cout << ans << endl;

    return 0;
}