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
    string s;
    cin>>s;
    vector<ll>w(n);
    rep(i,0,n)cin>>w[i];
    vector<ll>ch,ad;
    rep(i,0,n){
        if (s[i]=='0'){
            ch.push_back(w[i]);
        }else{
            ad.push_back(w[i]);
        }
    }
    sort(all(ch));
    sort(all(ad));
    ll ans = 0;
    rep(i,0,ad.size()){
        ll x = ad[i];
        auto idx = lower_bound(all(ch), x) - ch.begin();
        chmax(ans, (ll)ad.size()-i+idx);
    }
    chmax(ans, (ll)ch.size());
    chmax(ans, (ll)ad.size());
    cout << ans << endl;
    return 0;
}