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
    vector<ll>arr;
    rep(i,0,m){
        ll c;
        cin>>c;
        ll s = 0;
        rep(j,0,c){
            ll a;
            cin>>a;
            a--;
            s += (1LL<<a);
        }
        arr.push_back(s);
    }
    ll ans = 0;
    rep(bit,0,1<<m){
        ll s = 0;
        rep(i,0,m){
            if (bit&(1LL<<i)){
                s |= arr[i];
            }
        }
        if (s == ((1<<n)-1)) ans++;
    }
    cout << ans << endl;

    return 0;
}