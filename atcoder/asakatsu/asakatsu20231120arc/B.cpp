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
    ll t;
    cin>>t;
    while(t){
        t--;
        ll a,b,c;
        cin>>a>>b>>c;
        ll ans = 0;        
        b /= 2;
        
        // 6 + 4
        ll temp = min(b,c);
        ans += temp;
        b -= temp;
        c -= temp;

        // 4*2 + 2*1
        temp = min(a,c/2);
        ans += temp;
        a -= temp;
        c -= temp*2;

        // 6 + 2*2
        temp = min(b,a/2);
        ans += temp;
        b -= temp;
        a -= temp*2;

        // 4*1 + 2*3
        temp = min(c,a/3);
        ans += temp;
        c -= temp;
        a -= temp*3;        

        // 2*5
        ans += a/5;
        a -= a/5;

        cout << ans << endl;        
    }
    return 0;
}