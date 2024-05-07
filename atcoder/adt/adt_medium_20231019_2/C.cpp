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
const ll INF = numeric_limits<ll>::max();

int main()
{
    string s;
    cin>>s;
    set<char>st;
    ll n = s.size();
    bool flag1 = true;
    rep(i,0,n){
        st.insert(s[i]);
    }
    if (st.size()!=n)flag1=false;
    bool flag2 = false;
    rep(i,0,26){
        char c = 'A' + i;
        rep(j,0,n){
            if (c==s[j]) flag2 = true;
        }
    }
    bool flag3 = false;
    rep(i,0,26){
        char c = 'a' + i;
        rep(j,0,n){
            if (c==s[j]) flag3 = true;
        }
    }
    YesNo(flag1&flag2&flag3);

    return 0;
}