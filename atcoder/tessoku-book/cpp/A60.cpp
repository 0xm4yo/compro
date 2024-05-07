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
ll e(){ return -1; };

int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n), b(n);
    rep(i,0,n)cin>>a[i];
    b = a;
    map<ll,ll>mp;
    sort(all(b));
    rep(i,0,n)mp[b[i]]=i;
    segtree<ll,op,e>seg(n);
    rep(i,0,n){
        ll res = -1;
        ll pos = mp[a[i]];
        res = seg.prod(pos+1, n);
        cout << res << endl;
        seg.set(pos, i+1);
    }

    return 0;
}