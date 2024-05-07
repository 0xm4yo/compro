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
    ll ans = 0;
    ll k = 0;
    rep(i,0,10){
        if (s[i]=='o') k+=1LL<<i;
    }
    rep(i,0,10000){
        bool flag = true;
        auto x = i;
        ll temp = 0;
        rep(i,0,4){
            if (s[x%10] == 'x') flag = false;
            temp |= 1LL<<(x%10);
            x /= 10;
        }
        if (!flag) continue;
        if ((temp&k)!=k) continue;
        ans++;
    }
    cout << ans << endl;
    return 0;
}