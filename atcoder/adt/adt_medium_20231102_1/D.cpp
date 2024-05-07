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
    bool f = true;
    if (s.size()<8){
        cout << "No" << endl;
        return 0;
    } 
    if ('A'>s[0] || 'Z'<s[0]) f = false;
    ll off = 100000;
    ll temp = 0;
    rep(i,1,7){
        if ('A'<=s[i] && s[i]<='Z') { f = false; break; }
        temp += (s[i]-'0')*off;
        off/=10;
    }
    if (100000>temp || 999999 <temp) f = false;
    if ('A'>s[7] || 'Z'<s[7]) f = false;
    YesNo(f);
    return 0;
}