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
const ll INF = (ll)3e15;

ll op(ll a, ll b){ return a + b; };
ll e(){ return 0; };
int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    map<ll,ll>mp;
    rep(i,0,n)mp[a[i]] = i;
    segtree<ll,op,e>seg(n+1);
    rep(i,0,n){
        if (i%2 && i+1<n) seg.set(i, a[i+1]-a[i]);
    }

    ll q;
    cin>>q;
    while (q){
        q--;
        ll l, r;
        cin>>l>>r;
        ll lidx = lower_bound(all(a), l) - a.begin();
        ll ridx = lower_bound(all(a), r) - a.begin();
        if (l!=a[lidx]) lidx--;
        ll ans = seg.prod(lidx, ridx);
        if (lidx%2) ans -= l - a[lidx];
        if (ridx%2==0) ans -= a[ridx] - r;
        cout << ans << endl;
    }
    return 0;
}