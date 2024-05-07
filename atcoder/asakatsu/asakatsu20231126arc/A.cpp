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
    ll a,b,x,y;
    cin>>a>>b>>x>>y;
    if (a<b){
        ll l = 2*x*(b-a) + x;
        ll r = y*(b-a) + x;
        cout << min(l,r) << endl;
    }else if (a==b){
        cout << x << endl;        
    }else{
        ll l = 2*x*(a-b-1) + x;
        ll r = y*(a-b-1) + x;
        cout << min(l,r) << endl;
    }
    return 0;
}