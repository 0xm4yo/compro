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

double memo[310][310][310] = {0.0};
bool flag[310][310][310] = {false};

int main()
{
    ll n;
    cin>>n;
    vector<double>a(n);
    rep(i,0,n)cin>>a[i];
    function<double(ll,ll,ll)> f = [&](ll x, ll y, ll z){
        if (x<0||y<0||z<0) return 0.0;
        if (flag[x][y][z]) return memo[x][y][z];
        if (x+y+z==0) return 0.0;
        double c = (double)(n)/(double)(x+y+z);
        double xyz = (double)(x+y+z);
        double res = (double)z/xyz*f(x,y+1,z-1) + (double)y/xyz*f(x+1,y-1,z) + (double)x/xyz*f(x-1,y,z) + c;
        flag[x][y][z] = true;
        return memo[x][y][z] = res;
    };
    vector<ll> cnt(4);
    rep(i,0,n) cnt[a[i]]++;
    cout << fixed << setprecision(15) << f(cnt[1],cnt[2],cnt[3]) << endl;;
    return 0;
}