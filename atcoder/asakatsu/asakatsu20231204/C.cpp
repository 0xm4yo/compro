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
    ll n,m;
    cin>>n>>m;
    if (abs(n-m)>=2){
        cout << 0 << endl;
        return 0;
    }
    vector<mint> kai = {1};
    rep(i,2,100001){
        kai.push_back(kai.back()*i);
    }
    mint ans = kai[n-1] * kai[m-1];
    if (n==m) ans *= 2;
    cout << ans.val() << endl;


    return 0;
}