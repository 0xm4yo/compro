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

bool flag[500000] = {false};
ll memo[500000] = {0};
int main()
{
    ll n;
    cin>>n;
    vector<ll>t(n),k(n);
    vector<vector<ll>> a(n);
    rep(i,0,n){
        cin>>t[i]>>k[i];
        rep(j,0,k[i]){
            ll aa;
            cin>>aa;
            aa--;
            a[i].push_back(aa);
        }
    }
    vector<ll> v(n);
    function<ll(ll)> f = [&](ll now){
        if (flag[now])return memo[now];
        v[now] = 1;
        ll res = t[now];
        for (auto nex: a[now]){
            if (v[nex])continue;
            res += f(nex);
        }
        flag[now] = true;
        return memo[now] = res;
    };
    cout << f(n-1) << endl;
    return 0;
}