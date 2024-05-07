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
    ll n;
    cin>>n;
    ll cnt = 0;
    string ans = "";
    rep(i,1,10){
        rep(j,0,100){
            rep(k,0,10){
                rep(l,0,10){
                    rep(r,0,10){
                        cnt++;
                        if (cnt==n){
                            ans += char('0'+i);
                            ans += char('0'+i);
                            string temp = to_string(j);
                            if (temp.size()==1) temp = '0' + temp;
                            ans += temp;
                            ans += char('0'+k);
                            ans += char('0'+k);
                            ans += char('0'+l);
                            ans += char('0'+r);
                            ans += char('0'+l);
                            cout << ans << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}