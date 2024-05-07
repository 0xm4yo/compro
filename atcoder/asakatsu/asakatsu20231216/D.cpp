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
    vector<string> s(n);
    rep(i,0,n)cin>>s[i];
    ll a=0, b=0, ab=0, rem=0;
    rep(i,0,n){
        ll sz = s[i].size();
        if (s[i][0]=='B' && s[i][sz-1]=='A'){
            ab++;
        }else if(s[i][0]=='B'){
            b++;
        }else if(s[i][sz-1]=='A'){
            a++;
        }else{
            rem++;
        }
    }
    ll ans = ab;
    if (ab) ans--;
    if (ab && a){
        ans++;
        a--;
    }
    if (ab && b){
        ans++;
        b--;
    }
    ans += min(a,b);

    rep(i,0,n){
        ll sz = s[i].size();
        rep(j,0,sz-1){
            if (s[i][j]=='A' && s[i][j+1]=='B') ans++;
        }
    }
    cout << ans << endl;

    return 0;
}