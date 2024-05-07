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

ll op(ll a, ll b){return min(a, b);}
ll e(){ return INF; }

int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    ll s = 0;
    rep(i,0,k)s+=a[i];
    segtree<ll,op,e> seg(n);
    map<ll,ll> mp;
    auto b = a;
    sort(all(b));
    rep(i,0,n)mp[b[i]] = i;
    rep(i,0,n){
        if(i<k)continue;
        seg.set(mp[a[i]], min(seg.get(mp[a[i]]), i));
    }
    ll ans = INF;
    rep(i,0,k){
        chmin(ans, seg.prod(mp[a[i]]+1, n) - i);
    }

    if (ans>n)cout<<-1<<endl;
    else cout<<ans<<endl;


    return 0;
}