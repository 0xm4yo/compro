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
    while(t--){
        string s;
        cin>>s;
        ll sz = s.size();
        ll ans = 0;
        string temp = "";
        rep(i,0,sz-1) temp += '9';
        chmax(ans, stoll(temp));
        rep(i,1,sz/2+1){
            if (sz%i)continue;
            string t = "";
            rep(j,0,i) t += s[j];
            string t2 = "";
            rep(j,0,sz/i) t2 += t;

            if (stoll(t2)>stoll(s)){
                ll x = stoll(t);
                x--;
                t = to_string(x);
                t2 = "";
                rep(j,0,sz/i) t2 += t;
                chmax(ans, stoll(t2));
            }else{
                chmax(ans, stoll(t2));
            }
        }
        cout << ans << endl;

    }
    return 0;
}