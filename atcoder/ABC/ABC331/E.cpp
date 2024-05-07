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
    ll n,m,l;
    cin>>n>>m>>l;
    vector<ll>a(n),b(m);
    rep(i,0,n)cin>>a[i];
    rep(i,0,m)cin>>b[i];
    set<pair<ll,ll>> st;
    rep(i,0,l){
        ll c,d;
        cin>>c>>d;
        c--;d--;
        st.insert({c,d});
    }
    vector<pair<ll,ll>> c;
    rep(i,0,m){
        c.push_back({b[i],i});
    }
    sort(all(c));
    reverse(all(c));
    ll ans = 0;
    rep(i,0,n){
        for (auto [cost,idx]: c){
            if (st.find({i,idx})==st.end()){
                chmax(ans, a[i]+cost);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}