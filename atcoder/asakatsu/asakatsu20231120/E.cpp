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

ll dp[11][300001];

int main()
{
    ll d,g;
    cin>>d>>g;
    vector<ll>p(d),c(d);
    rep(i,0,d)cin>>p[i]>>c[i];
    rep(i,0,11)rep(j,0,300001)dp[i][j] = INF;
    dp[0][0] = 0;
    g /= 100;
    rep(i,0,d) c[i] /= 100;
    rep(i,0,d)rep(j,0,g+1){
        if (dp[i][j]==INF)continue;
        rep(k,0,p[i]){
            chmin(dp[i+1][min(g,j+(i+1)*k)], dp[i][j]+k);
        }
        chmin(dp[i+1][min(g,j+(i+1)*p[i]+c[i])], dp[i][j]+p[i]);
    }
    cout << dp[d][g] << endl;
    return 0;
}