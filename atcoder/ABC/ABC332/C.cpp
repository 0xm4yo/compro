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
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    ll l = -1;
    ll r = n;
    while(r-l>1){
        ll mid = (l+r)/2;
        ll nm = m;
        ll nt = mid;
        bool flag = true;
        rep(i,0,n){
            if (s[i]=='0'){
                nm = m;
                nt = mid;
            }else if(s[i]=='1'){
                if (nm){
                    nm--;
                }else if(nt){
                    nt--;
                }else{
                    flag = false;
                }
            }else{
                if (nt){
                    nt--;
                }else{
                    flag = false;
                }
            }
        }
        if (flag){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << r << endl;
    return 0;
}