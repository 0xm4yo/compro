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

ll op(ll a, ll b){ return max(a, b); };
ll e(){ return 0; };

int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    ll d;
    cin>>d;
    segtree<ll,op,e> seg(n+1);
    rep(i,0,n)seg.set(i+1,a[i]);
    while (d){
        d--;
        ll l,r;
        cin>>l>>r;
        ll ans = 0;
        chmax(ans, seg.prod(0,l));
        chmax(ans, seg.prod(r+1,n+1));
        cout << ans << endl;
    }

    return 0;
}