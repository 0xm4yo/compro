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
    ll h,w;
    cin>>h>>w;
    vector<string>s(h);
    rep(i,0,h)cin>>s[i];
    vector<pair<ll,ll>> arr;
    rep(i,0,h)rep(j,0,w){
        if (s[i][j]=='o') arr.push_back({i,j});
    }
    ll ans = 0;
    ans += abs(arr[0].first - arr[1].first);
    ans += abs(arr[0].second - arr[1].second);
    cout << ans << endl;
    return 0;
}