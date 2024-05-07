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
    vector<ll>x(n),y(n);
    rep(i,0,n)cin>>x[i]>>y[i];
    vector<pair<ll,ll>> ax,ay;
    rep(i,0,n) ax.push_back({x[i],i});
    rep(i,0,n) ay.push_back({y[i],i});
    sort(all(ax));
    sort(all(ay));
    vector<pair<ll,pair<ll,ll>>> arr;
    rep(i,0,3){
        rep(j,i+1,n){
            if (i==j) continue;
            if (i>j) swap(i,j);
            arr.push_back({abs(ax[i].first-ax[j].first),{ax[i].second,ax[j].second}});
            arr.push_back({abs(ay[i].first-ay[j].first),{ay[i].second,ay[j].second}});
        }
    }
    sort(all(arr));
    reverse(all(arr));
    pair<ll,ll> now = arr[0].second;
    for (auto [d,p]: arr){
        if (p==now) continue;
        cout << d << endl;
        break;
    }

    return 0;
}