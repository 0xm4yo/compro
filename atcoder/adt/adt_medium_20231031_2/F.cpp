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
    ll h,w;
    cin>>h>>w;
    vector<vector<ll>>a(h,vector<ll>(w));
    rep(i,0,h)rep(j,0,w)cin>>a[i][j];
    
    function<ll(ll,ll,set<ll>)> dfs = [&](ll nx, ll ny, set<ll> st){
        if (nx==h-1 && ny==w-1) return (ll)1;
        st.insert(a[nx][ny]);
        ll res = 0;
        if (nx+1<h){
            if (st.find(a[nx+1][ny])==st.end()) res += dfs(nx+1,ny,st);
        }
        if (ny+1<w){
            if (st.find(a[nx][ny+1])==st.end()) res += dfs(nx,ny+1,st);
        }
        return res;
    };
    cout << dfs(0,0,{}) << endl;

    
    return 0;
}
