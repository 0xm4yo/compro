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
    ll n,w;
    cin>>n>>w;
    vector<pair<ll,ll>> arr;
    rep(i,0,n){
        ll a,b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    sort(all(arr));
    reverse(all(arr));
    ll tot = 0;
    ll ans = 0;
    rep(i,0,n){
        auto [a, b] = arr[i];
        if (tot+b<=w){
            ans += a*b;
            tot += b;
        }else{
            ll rem = w - tot;
            ans += a*rem;
            tot += rem;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}