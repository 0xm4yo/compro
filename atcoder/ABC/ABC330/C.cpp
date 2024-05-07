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
    ll d;
    cin>>d;
    vector<ll>arr;
    rep(x,0,2LL*1000000){
        arr.push_back(x*x);
    }
    ll ans = INF;
    for(auto x2: arr){
        if (x2-d>=0){
            ll y2 = 0;
            chmin(ans, abs(x2+y2-d));
        }else{
            ll idx = lower_bound(all(arr), abs(x2-d)) - arr.begin();
            rep(i, max(0LL,idx-5),min((ll)arr.size(),idx+5LL)){
                ll y2 = arr[i];
                chmin(ans, abs(x2+y2-d));
            }
        }
    }
    cout << ans << endl;

    return 0;
}