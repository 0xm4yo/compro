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
    string ans = "";
    if (0<=s[0]-'A' && s[0]-'A'<26){
        ans += s[0];
    }else{
        ll cnt = s[0] - 'a';
        char t = 'A' + cnt;
        ans += t;
    }
    rep(i,1,n){
        if (0<=s[i]-'a' && s[i]-'a' <26){
            ans += s[i];
        }else{
            ll cnt = s[i] - 'A';
            char t = 'a' + cnt;
            ans += t;
        }
    }
    cout << ans << endl;
    return 0;
}