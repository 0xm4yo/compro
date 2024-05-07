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
    ll cum = accumulate(all(a),0LL);
    ll m = cum%n;
    vector<ll>arr;
    rep(i,0,m)arr.push_back(cum/n+1);
    while(arr.size()<n){
        arr.push_back(cum/n);
    }
    sort(all(arr));
    sort(all(a));
    ll ans = 0;
    rep(i,0,n) ans += abs(arr[i]-a[i]);
    cout << ans/2 << endl;
    return 0;
}