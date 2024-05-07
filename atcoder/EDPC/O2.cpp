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
bool flag[22][1<<22] = {false};
mint memo[22][1<<22] = {0};

int main()
{
    ll n;
    cin>>n;
    vector<vector<ll>>a(n,vector<ll>(n));
    rep(i,0,n)rep(j,0,n)cin>>a[i][j];

    function<mint(ll,ll)> f = [&](ll cnt, ll s){
        if (cnt==n) return (mint)1;
        if (flag[cnt][s])return memo[cnt][s];
        mint res = 0;
        rep(i,0,n){
            if (s&(1LL<<i)) continue;
            if (a[cnt][i]==0) continue;
            res += f(cnt+1, s+(1LL<<i));
        }
        flag[cnt][s] = true;
        return memo[cnt][s] = res;
    };
    cout << f(0,0).val() << endl;
    
    
    return 0;
}