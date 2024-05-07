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
    vector<ll> a(3);
    rep(i,0,3) cin>>a[i];
    map<ll,ll>mp;
    rep(i,0,3) mp[a[i]]++;
    rep(i,0,3){
        if (mp[a[i]]==1){
            cout << a[i] << endl;
            return 0;
        }
    }
    cout << a[0] << endl;

    return 0;
}