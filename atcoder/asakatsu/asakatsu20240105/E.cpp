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
    map<ll,ll> mp;
    vector<vector<pair<ll,ll>>> arr(n);
    rep(i,0,n){
        ll m;
        cin>>m;
        rep(j,0,m){
            ll p,e;
            cin>>p>>e;
            chmax(mp[p],e);
            arr[i].push_back({p,e});
        }
    }
    ll ans = 0;
    rep(i,0,n){
        for (auto [p,e]: arr[i]){
            chmax(mp[p],e);
        }
    }
    map<pair<ll,ll>,ll> mp2;
    rep(i,0,n){
        for (auto [p,e]: arr[i]){
            if (mp[p]==e){
                mp2[{p,e}]++;
            }
        }
    }
    bool flag2 = false;
    rep(i,0,n){
        bool flag = false;
        for (auto [p,e]: arr[i]){
            if (mp[p]==e){
                if (mp2[{p,e}]==1) flag = true;
            }
        }
        if (flag) ans++;
        else flag2 = true;
    }
    if (flag2) ans++;
    cout << ans << endl;

    return 0;
}