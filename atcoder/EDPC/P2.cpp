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
bool flag[100010][2] = {false};
mint memo[100010][2] = {0};

int main()
{
    ll n;
    cin>>n;
    vector<vector<ll>>g(n);
    rep(i,0,n-1){
        ll x,y;
        cin>>x>>y;
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<bool> v(n);
    function<mint(ll,ll)> f = [&](ll now, ll mode){
        if (flag[now][mode]) return memo[now][mode];
        v[now] = true;
        mint res = 1;
        for (auto nex: g[now]){
            if (v[nex])continue;
            if (mode){
                res *= f(nex, 0);
            }else{
                res *= f(nex, 0) + f(nex, 1);
            }
        }
        v[now] = false;
        flag[now][mode] = true;
        return memo[now][mode] = res;
    };
    mint ans = f(0,0) + f(0,1);
    cout << ans.val() << endl;
    
    return 0;
}