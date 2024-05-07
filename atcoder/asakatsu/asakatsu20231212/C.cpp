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
    vector<ll>a(n),b(n);
    rep(i,0,n)cin>>a[i]>>b[i];

    auto comp = [&](ll i, ll j){
        ll l = a[i]*(a[j]+b[j]);
        ll r = a[j]*(a[i]+b[i]);
        if (l==r){
            return i < j;
        }else{
            return l > r;
        }
    };
    vector<ll>arr;
    rep(i,0,n)arr.push_back(i);
    stable_sort(all(arr), comp);
    for (auto x: arr){
        cout << x+1 << endl;
    }
    return 0;
}