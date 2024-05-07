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
const double INF = 1e15;

int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    double l = 0.0;
    double r = 200.0;
    rep(i,0,200){
    // while(r-l>0.000000000001){
        double mid = (l+r)/2.0;
        double f = (double)a*mid + (double)b*sin(c*mid*pi) - 100.0;
        if (f<0.0){
            l = mid;
        }else{
            r = mid;
        }
    }
    // double f = (double)a*l + (double)b*sin(c*l*pi) - 100.0;
    cout << fixed << setprecision(15) << l << endl;
    return 0;
}