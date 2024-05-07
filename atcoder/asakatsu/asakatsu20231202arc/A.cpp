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
        ll n;
        string s;
        cin>>n>>s;
        bool flag = false;
        rep(i,0,n){
            string a="", b="";
            rep(j,0,i) a += s[j];
            rep(j,i,n) b += s[j];
            if (a=="") continue;
            if (b=="") continue;
            if (a<b) flag = true;
        }
        YesNo(flag);
    }

    return 0;
}