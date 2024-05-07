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
    vector<ll>p(m),y(m);
    rep(i,0,m)cin>>p[i]>>y[i];
    vector<vector<ll>>arr(n+1);
    rep(i,0,m){
        arr[p[i]].push_back(y[i]);
    }
    rep(i,0,n+1) sort(all(arr[i]));
    rep(i,0,m){
        string s1 = to_string(p[i]);
        s1 = std::string(std::max(0, 6-(int)s1.size()), '0') + s1;
        int idx = lower_bound(all(arr[p[i]]), y[i]) - arr[p[i]].begin();
        idx++;
        string s2 = to_string(idx);
        s2 = std::string(std::max(0, 6-(int)s2.size()), '0') + s2;
        string ans = s1 + s2;
        cout << ans << endl;

    }
    return 0;
}