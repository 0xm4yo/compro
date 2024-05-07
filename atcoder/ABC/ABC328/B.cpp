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
    vector<ll>d(n);
    rep(i,0,n)cin>>d[i];
    ll ans = 0;
    rep(i,1,n+1){
        rep(j,1,d[i-1]+1){
            set<ll> st;
            st.insert(i%10);
            if (i/10) st.insert(i/10);
            st.insert(j%10);
            if (j/10) st.insert(j/10);            
            if (st.size()==1)ans++;
        }
    }
    cout << ans << endl;
    return 0;
}