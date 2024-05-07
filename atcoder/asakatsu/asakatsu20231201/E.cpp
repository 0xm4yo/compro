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

using mint = modint1000000007;

int main()
{
    ll h,w;
    cin>>h>>w;
    vector<string>s(h);
    rep(i,0,h)cin>>s[i];
    vector<vector<mint>>dp(h,vector<mint>(w));
    dp[0][0] = 1;
    vector<vector<mint>> cumh(h,vector<mint>(w)),cumw(h,vector<mint>(w)),cumhw(h,vector<mint>(w));
    cumh[0][0] = 1;
    cumw[0][0] = 1;
    cumhw[0][0] = 1;
    rep(i,0,h)rep(j,0,w){
        if (s[i][j]=='#') continue;
        if (i==0 && j==0) continue;
        mint temp = 0;
        if (i-1>=0) temp += cumh[i-1][j];
        if (j-1>=0) temp += cumw[i][j-1];
        if (i-1>=0 && j-1>=0) temp += cumhw[i-1][j-1];
        cumh[i][j] = temp;
        cumw[i][j] = temp;
        cumhw[i][j] = temp;
        if (i-1>=0) cumh[i][j] += cumh[i-1][j];
        if (j-1>=0) cumw[i][j] += cumw[i][j-1];
        if (i-1>=0 && j-1>=0) cumhw[i][j] += cumhw[i-1][j-1];
        dp[i][j] = temp;
    }
    cout << dp[h-1][w-1].val() << endl;
    return 0;
}