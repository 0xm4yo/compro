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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    pair<ll,ll> p = {0,0};
    bool flag = false;
    set<pair<ll,ll>> st;
    st.insert(p);
    rep(i,0,n){
        if (s[i]=='R') p.first += 1;
        if (s[i]=='L') p.first -= 1;
        if (s[i]=='U') p.second += 1;
        if (s[i]=='D') p.second -= 1;
        if (st.find(p)!=st.end()) flag=true;
        else st.insert(p);
    }
    YesNo(flag);
    return 0;
}