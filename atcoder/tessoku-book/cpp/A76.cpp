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

using mint = modint1000000007;

mint op(mint a, mint b){ return a + b; };
mint e(){ return 0; };

int main()
{
    ll n,w,l,r;
    cin>>n>>w>>l>>r;
    vector<ll>x(n+2);
    rep(i,1,n+1)cin>>x[i];
    x[n+1] = w;
    segtree<mint,op,e> seg(n+2);
    seg.set(0,1);
    rep(i,1,n+2){
        ll now = x[i];
        ll left = now - r;
        ll right = now - l;
        ll lidx = lower_bound(all(x), left) - x.begin();
        ll ridx = lower_bound(all(x), right) - x.begin();
        if (x[lidx]<left) lidx++;
        if (x[ridx]==right) ridx++;
        mint temp = seg.prod(lidx, ridx);
        seg.set(i, temp);
    }
    cout << seg.get(n+1).val() << endl;

    return 0;
}