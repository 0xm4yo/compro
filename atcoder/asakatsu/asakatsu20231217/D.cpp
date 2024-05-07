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
    string s;
    cin>>s;
    ll n = s.size();
    ll now = 0;
    ll ans = 0;
    rep(i,0,n){
        if (s[i]=='A'){
            now++;
        }else{
            if (s[i]=='C'){
                now = 0;
            }else{
                if (i+1>=n)continue;
                if (s[i+1]=='C'){
                    ans += now;
                    i++;
                }else{
                    now = 0;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}