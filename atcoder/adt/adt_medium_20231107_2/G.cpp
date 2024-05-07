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
    vector<vector<ll>>d(n, vector<ll>(n));
    rep(i,0,n-1)rep(j,i+1,n)cin>>d[i][j];

    vector<ll>dp((1LL<<n)+1);
    rep(i,0,1LL<<n){
        ll st = -1;
        rep(k,0,n){
            if (i&(1LL<<k))continue;
            st = k;
            break;
        }
        if (st==-1)continue;
        rep(k,st+1,n){
            if (i&(1LL<<k))continue;
            chmax(dp[i+(1LL<<st)+(1LL<<k)], dp[i]+d[st][k]);
        }
    }
    cout << dp[(1LL<<n)-1] << endl;
    return 0;
}