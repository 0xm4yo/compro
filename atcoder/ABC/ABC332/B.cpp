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
    ll k,g,m;
    cin>>k>>g>>m;
    ll ng = 0;
    ll nm = 0;
    while(k){
        k--;
        if (ng == g){
            ng = 0;
        }else if (nm == 0){
            nm = m;
        }else{
            ll tot = ng + nm;
            ll rem = tot - g;
            if (rem>0){
                ng = g;
                nm = rem;
            }else{
                ng = tot;
                nm = 0;
            }
        }
    }
    cout << ng << endl;
    cout << nm << endl;
    return 0;
}