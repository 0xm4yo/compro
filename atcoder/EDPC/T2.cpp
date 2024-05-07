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

mint op(mint a, mint b) {return a+b; };
mint e(){ return (mint)0; };

int main()
{
    ll n;
    string s;
    cin>>n>>s;
    vector<vector<mint>> dp(n+1, vector<mint>(n+1,0));
    segtree<mint,op,e> seg(n+1);
    seg.set(0,(mint)1);
    seg.set(n,(mint)-1);
    rep(i,1,n){
        rep(j,0,n)dp[i][j] = seg.prod(0,j+1);
        rep(j,0,n+1) seg.set(j,0);
        rep(j,0,n){
            ll rem = n-i;
            ll less = j;
            ll more = rem-less;
            if (s[i-1] == '<'){
                if (more < 0) break;
                // rep(k,0,more) dp[i+1][j+k] += dp[i][j];
                seg.set(j, seg.get(j)+dp[i][j]);
                seg.set(j+more, seg.get(j+more)-dp[i][j]);
            }else{
                // rep(k,0,less) dp[i+1][j-k-1] += dp[i][j];
                seg.set(j, seg.get(j)-dp[i][j]);
                seg.set(j-less, seg.get(j-less)+dp[i][j]);                              
            }
        }
    }
    rep(j,0,n)dp[n][j] = seg.prod(0,j+1);
    cout << dp[n][0].val() << endl;
    
    return 0;
}