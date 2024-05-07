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

ll dp[2020][2020] = {-INF};

int main()
{
    string s,t;
    cin>>s>>t;
    dp[0][0] = 0;
    rep(i,1,s.size()+1)rep(j,1,t.size()+1){
        ll c = 0;
        if (s[i-1] == t[j-1]) c = 1;
        chmax(dp[i][j], dp[i-1][j]);
        chmax(dp[i][j], dp[i][j-1]);
        chmax(dp[i][j], dp[i-1][j-1] + c);
    }
    cout << dp[s.size()][t.size()] << endl;
    return 0;
}