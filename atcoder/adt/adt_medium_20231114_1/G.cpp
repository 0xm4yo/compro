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
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    vector<vector<ll>>arr(n+1);
    rep(i,0,n){
        arr[a[i]].push_back(i);
    }
    ll q;
    cin>>q;
    while(q){
        q--;
        ll l,r,x;
        cin>>l>>r>>x;
        l--;r--;
        auto lidx = lower_bound(all(arr[x]), l) - arr[x].begin();
        auto ridx = upper_bound(all(arr[x]), r) - arr[x].begin();
        ll ans = ridx - lidx;
        cout << ans << endl;
    }
    return 0;
}