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
    ll n,c;
    cin>>n>>c;
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(50, vector<ll>(2)));
    rep(i,0,n+1)rep(j,0,50) dp[i][j][1] = 1;
    rep(i,0,n){
        ll t,a;
        cin>>t>>a;
        rep(j,0,50){
            ll bit = 0;
            if (a&(1LL<<j)) bit = 1;
            rep(k,0,2){
                if (t==1){
                    dp[i+1][j][k] = dp[i][j][k] & bit;
                }else if(t==2){
                    dp[i+1][j][k] = dp[i][j][k] | bit;
                }else{
                    dp[i+1][j][k] = dp[i][j][k] ^ bit;
                }
            }
        }
        
        ll temp = 0;
        rep(j,0,50){
            ll bit = 0;
            if (c&(1LL<<j)) bit = 1;
            temp += (1LL<<j) * dp[i+1][j][bit];
        }
        c = temp;
        cout << c << endl;
    }
    
    return 0;
}