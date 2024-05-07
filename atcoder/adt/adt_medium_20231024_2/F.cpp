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
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll>rd(n+1),bl(n+1);
    rd[n] = 1;
    rrep(i,n,2){
        bl[i] += rd[i]*x;
        rd[i-1] += rd[i];
        rd[i-1] += bl[i];
        bl[i-1] += bl[i]*y;
    }
    cout << bl[1] << endl;
    return 0;
}