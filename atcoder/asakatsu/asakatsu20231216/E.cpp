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

using mint = static_modint<2019>;

int main()
{
    string s;
    cin>>s;
    ll n = s.size();
    vector<mint> cum = {0};
    rep(i,0,n){
        cum.push_back(cum.back()+(s[i]-'0')*pow_mod(10,n-i-1,2019)); 
    }

    map<ll,ll> mp;
    ll ans = 0;
    mp[0]++;
    rep(j,1,n+1){
        ans += mp[cum[j].val()];
        mp[cum[j].val()]++;
    }
    cout << ans << endl;

    return 0;
}