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
    ll n,q;
    cin>>n>>q;
    set<pair<ll,ll>> st;
    while (q){
        q--;
        ll t,a,b;
        cin>>t>>a>>b;
        a--;b--;
        if (t==1){
            st.insert({a,b});
        }
        if (t==2){
            if (st.find({a,b})==st.end()) continue;
            st.erase({a,b});
        }
        if (t==3){
            YesNo(st.find({a,b})!=st.end() && st.find({b,a})!=st.end());
        }
    }
    return 0;
}