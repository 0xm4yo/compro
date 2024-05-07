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
const ll INF = (ll)1e15;

ll dp[40][40] = {0};

int main()
{
    ll h,w;
    cin>>h>>w;
    vector<string> s(h+1);
    rep(i,0,h)cin>>s[i];
    rep(i,0,h)s[i]+='#';
    rep(j,0,w)s[h]+='#';

    dp[0][0] = 1;
    rep(i,0,h)rep(j,0,w){
        if (s[i+1][j] == '.') dp[i+1][j] += dp[i][j];
        if (s[i][j+1] == '.') dp[i][j+1] += dp[i][j];
    }
    cout << dp[h-1][w-1] << endl;

    return 0;
}