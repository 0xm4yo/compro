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

int main()
{
    string s,t;
    cin>>s>>t;
    ll n = s.size();
    ll m = t.size();
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
    rep(i,1,n+1)rep(j,1,m+1){
        ll c = 0;
        if (s[i-1]==t[j-1]) c = 1;
        chmax(dp[i][j], dp[i-1][j-1] + c);
        chmax(dp[i][j], dp[i-1][j]);
        chmax(dp[i][j], dp[i][j-1]);
    }
    ll pos = m;
    string ans = "";
    ll cnt = dp[n][m];
    rrep(i,n,1){
        if (cnt == 0) break;
        rrep(j,pos,1){
            if (dp[i][j]==cnt && dp[i][j]-dp[i-1][j-1]==1 && dp[i][j]-dp[i-1][j]==1 && dp[i][j]-dp[i][j-1]==1){
                ans += s[i-1];
                pos = j-1;
                cnt--;
                break;
            }
        }
    }
    reverse(all(ans));
    cout << ans << endl;

    return 0;
}