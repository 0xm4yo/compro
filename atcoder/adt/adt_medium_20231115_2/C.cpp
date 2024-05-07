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
    vector<string>s(n);
    rep(i,0,n)cin>>s[i];
    vector<char> aa = {'H' , 'D' , 'C' , 'S'};
    vector<char> bb = {'A' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , 'T' , 'J' , 'Q' , 'K' };
    bool flag = true;
    set<string>st;
    rep(i,0,n){
        if (find(all(aa), s[i][0])==aa.end()) flag = false;
        if (find(all(bb), s[i][1])==bb.end()) flag = false;
        st.insert(s[i]);
    }
    if (st.size()!=n)flag = false;
    YesNo(flag);
    return 0;
}