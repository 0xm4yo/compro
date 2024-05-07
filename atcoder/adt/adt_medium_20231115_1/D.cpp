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
    vector<string> s(n),t(n);
    rep(i,0,n)cin>>s[i]>>t[i];
    bool flag = true;
    map<string,ll>mp;
    rep(i,0,n){
        mp[s[i]]++;
        mp[t[i]]++;
    }
    rep(i,0,n){
        if (s[i]==t[i]){
            if (mp[s[i]]>2)flag=false;
        }else{
            if (mp[s[i]]!=1&&mp[t[i]]!=1) flag=false;
        }
    }
    YesNo(flag);
    return 0;
}