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
    ll n,cost;
    cin>>n>>cost;
    vector<pair<ll,ll>> arr;
    rep(i,0,n){
        ll a,b,c;
        cin>>a>>b>>c;
        arr.push_back({a,c});
        arr.push_back({b+1,-c});
    }
    sort(all(arr));
    ll ans = 0;
    ll time = 0;
    ll nowc = 0;
    for (auto [t, c]: arr){
        if (t!=time){
            ans += min(cost, nowc) * (t-time);
            nowc += c;
            time = t;
        }else{
            nowc += c;
        }
    }
    cout << ans << endl;
    return 0;
}