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
mint dp[10010][110][2] = {0};

int main()
{
    string s;
    cin>>s;
    ll d;
    cin>>d;    

    ll n = s.size();
    dp[0][0][1] = 1;
    rep(i,0,n)rep(j,0,d)rep(flag,0,2){
        if (dp[i][j][flag]==0) continue;
        ll mx = s[i] - '0';
        rep(k,0,10){
            if (mx>k) dp[i+1][(j+k)%d][0] += dp[i][j][flag];
            else if(mx==k) dp[i+1][(j+k)%d][flag] += dp[i][j][flag];
            else {
                if (!flag) dp[i+1][(j+k)%d][0] += dp[i][j][flag];
            }
        }
    }
    mint ans = dp[n][0][0] + dp[n][0][1] - 1;
    cout << ans.val() << endl;

    return 0;
}