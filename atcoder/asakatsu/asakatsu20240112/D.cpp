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
    ll n,m,q;
    cin>>n>>m>>q;
    vector<ll>w(n),v(n);
    rep(i,0,n)cin>>w[i]>>v[i];
    vector<ll>x(m);
    rep(i,0,m)cin>>x[i];

    vector<pair<ll,ll>> arr;
    rep(i,0,n)arr.push_back({v[i],w[i]});
    sort(all(arr));
    reverse(all(arr));

    while(q--){
        ll l,r;
        cin>>l>>r;
        l--;r--;
        vector<ll> y;
        rep(i,0,m){
            if (l<=i && i<=r) continue;
            y.push_back(x[i]);
        }

        sort(all(y));
        ll sz = y.size();
        vector<bool> vis(sz);
        ll ans = 0;
        for (auto [vv,ww]: arr){
            auto idx = lower_bound(all(y), ww) - y.begin();
            while(idx<sz){
                if (vis[idx]){
                    idx++;
                    continue;
                }
                vis[idx] = true;
                ans += vv;
                break;
            }
        }
        cout << ans << endl;
        
    }

    return 0;
}