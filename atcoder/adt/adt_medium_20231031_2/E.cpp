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
const ll INF = numeric_limits<ll>::max();

int main()
{
    ll n,d;
    cin>>n>>d;
    vector<bool>v(n);
    dsu uf(n);
    auto f = [&](ll ax, ll ay, ll bx, ll by){
        double dif = sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
        if (dif<=(double)d) return true;
        else return false;
    };
    vector<ll>x(n),y(n);
    rep(i,0,n) cin>>x[i]>>y[i];
    rep(i,0,n)rep(j,0,n){
        if (f(x[i],y[i],x[j],y[j])) uf.merge(i,j);
    }
    rep(i,0,n)if(uf.same(0,i))v[i]=true;
    rep(i,0,n)YesNo(v[i]);
    return 0;
}