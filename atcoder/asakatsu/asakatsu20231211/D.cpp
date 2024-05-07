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
    ll n,m;
    cin>>n>>m;
    vector<ll>k(m);
    vector<vector<ll>> s(m);
    rep(i,0,m){
        cin>>k[i];
        rep(j,0,k[i]){
            ll ss;
            cin>>ss;
            ss--;
            s[i].push_back(ss);
        }
    }
    vector<ll>p(m);
    rep(i,0,m)cin>>p[i];
    ll ans = 0;
    rep(bit,0,1LL<<n){
        bool flag = true;
        rep(i,0,m){
            ll temp = 0;
            for (auto x: s[i]){
                if (bit&(1LL<<x)) temp++;
            }
            temp %= 2;
            if (temp!=p[i]) flag = false;
        }
        if (flag) ans++;        
    }
    cout << ans << endl;

    return 0;
}