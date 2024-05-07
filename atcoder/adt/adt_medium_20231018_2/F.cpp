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

int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n),b(n);
    rep(i,0,n)cin>>a[i]>>b[i];
    ll s = accumulate(all(a), 0LL);
    double l = 0;
    double r = s;
    while (r-l>0.00000001){
        double mid = (l+r)/2.0;
        double lt = 0;
        double lnow = 0;
        rep(i,0,n){
            if ((double)a[i]/(double)b[i] + lt < mid){
                lt += (double)a[i]/(double)b[i];
                lnow += a[i];
            }else{
                lnow += b[i]*(mid-lt);
                break;
            }
        }

        double rt = 0;
        double rnow = 0;
        rrep(i,n-1,0){
            if ((double)a[i]/(double)b[i] + rt < mid){
                rt += (double)a[i]/(double)b[i];
                rnow += a[i];
            }else{
                rnow += b[i]*(mid-rt);
                break;
            }
        }
        if (lnow + rnow < s){
            l = mid;
        }else{
            r = mid;
        }
    }
    double ans = 0.0;
    double lt = 0;
    rep(i,0,n){
        if ((double)a[i]/(double)b[i] + lt < l){
            lt += (double)a[i]/(double)b[i];
            ans += a[i];
        }else{
            ans += b[i]*(l-lt);
            break;
        }
    }
    cout << fixed << setprecision(15) << ans << endl;
    
    return 0;
}