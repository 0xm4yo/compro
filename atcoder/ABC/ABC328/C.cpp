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

ll op(ll a, ll b){return a+b;}
ll e(){return 0;}

int main()
{
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<ll>a(n);
    segtree<ll,op,e>seg(n);
    rep(i,1,n){
        if (s[i]==s[i-1]) a[i] = 1;
    }
    rep(i,0,n)seg.set(i,a[i]);
    while (q){
        q--;
        ll l,r;
        cin>>l>>r;
        cout << seg.prod(l,r) << endl;
    }
    return 0;
}