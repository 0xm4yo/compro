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
    ll n,k;
    cin>>n>>k;
    double ans = 0.0;
    rep(i,1,n+1){
        double temp = 1.0/(double)n;
        ll now = i;
        ll cnt = 0;
        while(now<k){
            now *= 2;
            cnt++;
        }
        temp *= powl(0.5,cnt);
        ans += temp;
    }
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}