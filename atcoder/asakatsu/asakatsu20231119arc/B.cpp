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
    ll n,a,b;
    cin>>n>>a>>b;
    if (n<a){
        cout << 0 << endl;
        return 0;
    }
    if (a<b){
        cout << n - (a-1) << endl;
    }else{
        ll rem = n%a;
        ll ans = min(rem, b-1);
        ans += ((n/a)-1)*b;
        ans += 1;
        cout << ans << endl;
    }
    
    return 0;
}