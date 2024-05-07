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
const ll INF = (ll)3e15;

int main()
{
    string s;
    cin>>s;
    ll pos = 0;
    ll ans = 0;
    ll n = s.size();
    while (pos<n){
        if (pos < n-1 && s[pos]=='0' && s[pos+1]=='0'){
            ans++;
            pos+=2;
        }else{
            ans++;
            pos++;
        }
    }
    cout << ans << endl;
    return 0;
}