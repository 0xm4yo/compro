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

using mint = modint1000000007;
mint dp[1100][1100] = {0};

int main()
{
    ll h,w;
    cin>>h>>w;
    vector<string> a(h+1);
    rep(i,0,h){ cin>>a[i]; a[i]+='#'; };
    rep(j,0,w+1) a[h]+='#';
    dp[0][0] = 1;
    rep(i,0,h)rep(j,0,w){
        if (a[i][j]=='#')continue;
        if (a[i+1][j]=='.') dp[i+1][j] += dp[i][j];
        if (a[i][j+1]=='.') dp[i][j+1] += dp[i][j];
    }
    cout << dp[h-1][w-1].val() << endl;

    return 0;
}