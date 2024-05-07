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
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    set<ll> b;
    rep(i,0,n)b.insert(a[i]);
    vector<ll>c;
    for (auto bb: b){
        c.push_back(bb);
    }
    vector<ll>ans(n+1);
    rep(i,0,n){
        auto idx= upper_bound(all(c), a[i]) - c.begin();
        ans[c.size()-idx]++;
    }
    rep(i,0,n) cout << ans[i] << endl;
    return 0;
}