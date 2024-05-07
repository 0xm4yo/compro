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
    ll n;
    cin>>n;
    function<vector<ll>(ll)> f = [&](ll now){
        vector<ll> res;
        if (now == 1){
            res.push_back(1);
            return res;
        }
        auto temp = f(now-1);
        for (auto x: temp) res.push_back(x);
        res.push_back(now);
        for (auto x: temp) res.push_back(x);
        return res;
    };

    auto ans = f(n);
    for (auto x: ans)cout << x << endl;
    return 0;
}