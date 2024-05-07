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

ll op(ll a, ll b){return a+b; }
ll e(){ return 0LL; }

int main()
{
    ll t;
    cin>>t;
    while(t){
        t--;
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        segtree<ll,op,e> seg(n), seg1(n);
        rep(i,0,n)if(s[i]!='0') seg.set(i,1);
        rep(i,0,n)if(s[i]=='1') seg1.set(i,1);
        ll temp = 0;
        rep(i,0,n-k+1){
            if (s[i]==0)continue;
            if (seg1.prod(0,i))continue;
            if (seg1.prod(i+k,n))continue;
            if (seg.prod(i,i+k)==k) temp++;
        }
        bool flag = false;
        if (temp==1) flag = true;
        YesNo(flag);
    }
    return 0;
}