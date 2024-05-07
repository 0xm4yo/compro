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
        cin>>n;
        vector<string> s(3);
        rep(i,0,3)cin>>s[i];
        rep(i,0,3)s[i]+=s[i];
        string temp ="";
        rep(i,0,n) temp += '0';
        rep(i,0,n) temp += '1';
        temp += '0';
        cout << temp << endl;
    }

    return 0;
}