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
const ll INF = numeric_limits<ll>::max();

int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,0,n)cin>>a[i];
    vector<ll>arr;
    arr.push_back(0);
    rep(i,0,n){
        ll lt = arr.back();
        arr.push_back((lt+a[i])%360);
    }
    sort(all(arr));
    arr.push_back(360);
    ll ans = 0;
    rep(i,0,n+1){
        chmax(ans, arr[i+1]-arr[i]);
    }
    cout << ans << endl;
    return 0;
}