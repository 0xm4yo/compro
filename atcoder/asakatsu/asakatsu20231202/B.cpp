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
    ll b = 0;
    rrep(i,n-1,0){
        if (s[i]=='a') b++;
        else break;
    }
    ll a = 0;
    rep(i,0,n){
        if (s[i]=='a') a++;
        else break;
    }
    if (a==b && a==n){
        cout << "Yes" << endl;
        return 0;
    }
    if (a>b){
        cout << "No" << endl;
        return 0;
    }
    string t = "";
    while(a<b){
        t += 'a';
        a++;
    }
    t += s;
    bool flag = true;
    n = t.size();
    rep(i,0,n){
        if(t[i]!=t[n-i-1]) flag = false;
    }
    YesNo(flag);
    return 0;
}