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
const ll INF = numeric_limits<ll>::max();

int main()
{
    ll n,m,t;
    cin>>n>>m>>t;
    vector<ll>a(n-1);
    rep(i,0,n-1)cin>>a[i];
    vector<ll>b(n);
    rep(i,0,m){
        ll x,y;
        cin>>x>>y;
        x--;
        b[x] = y;
    }
    
    bool flag = true;
    rep(i,0,n-1){
        if (t > a[i]){
            t -= a[i];
            t += b[i+1];
        }else{
            flag = false;
            break;
        }
    }
    YesNo(flag);
    return 0;
}