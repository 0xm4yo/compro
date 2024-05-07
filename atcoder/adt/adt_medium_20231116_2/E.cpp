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
    string s;
    cin>>s;
    ll l = 0;
    ll r = n+10;
    while (r-l>1){
        ll mid = (l+r)/2;
        string t1 = "";
        rep(i,0,mid){
            t1 += 'o';
        }
        t1 += '-';
        string t2 = "";
        t2 += '-';
        rep(i,0,mid){
            t2 += 'o';
        }
        if (s.find(t1)==string::npos && s.find(t2)==string::npos){
            r = mid;
        }else{
            l = mid;
        }
    }
    if (l==0) cout << -1 << endl;
    else cout << l << endl;
    return 0;
}