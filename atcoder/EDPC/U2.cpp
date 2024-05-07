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

bool flag[1<<20] = {false};
ll memo[1<<20] = {0};

int main()
{
    ll n;
    cin>>n;
    vector<vector<ll>>a(n, vector<ll>(n));
    rep(i,0,n)rep(j,0,n)cin>>a[i][j];

    function<ll(ll)> f = [&](ll s){
        if (flag[s])return memo[s];
        ll res = -INF;
        ll temp = 0;
        vector<ll> arr;
        rep(i,0,n) if (s&(1LL<<i)) arr.push_back(i);
        for(auto x: arr)for(auto y: arr)temp+=a[x][y];
        temp /= 2;
        chmax(res, temp);
        ll t = s;
        while (t>0){
            t--;
            t &= s;
            if (t==0) chmax(res, temp);
            else chmax(res, f(t) + f(s-t));
        }
        flag[s] = true;
        return memo[s] = res;
    };
    
    cout << f((1<<n)-1) << endl;

    return 0;
}