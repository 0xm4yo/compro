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
const ll INF = (ll)1e15;

int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    auto b = a;
    sort(all(b));
    map<ll,ll> mp;
    ll cnt = 0;
    rep(i,0,n){
        if (mp.find(b[i])==mp.end()){
            cnt++;
            mp[b[i]] = cnt;
        }
    }
    rep(i,0,n){
        cout << mp[a[i]] << endl;
    }
    return 0;
}