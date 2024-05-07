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
const ll INF = (ll)1e15;

int main()
{
    ll n,m;
    cin>>n>>m;
    dsu uf(n);
    vector<tuple<ll,ll,ll>> arr;
    rep(i,0,m){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        arr.push_back({c,a,b});
    }
    sort(all(arr));
    ll ans = 0;
    for (auto [c,a,b]: arr){
        if (uf.same(a,b)) continue;
        ans += c;
        uf.merge(a,b);
    }
    cout << ans << endl;
    return 0;
}