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
const ll INF = (ll)1e15;

int main()
{
    ll n,L;
    cin>>n>>L;
    ll k;
    cin>>k;
    vector<ll>a(n+2);
    rep(i,1,n+1)cin>>a[i];
    a[n+1] = L;
    vector<ll>dif(n+1);
    rep(i,1,n+2){
        dif[i-1] = a[i] - a[i-1];
    }
    ll l = *min_element(all(dif));
    ll r = INF;
    while (r-l>1){
        ll mid = (l+r)/2;
        ll pos = -1;
        ll tot = 0;
        ll temp = 0;
        while (1){
            pos++;
            if (pos==n){
                tot += dif[pos];
                if (tot>=mid)temp++;
                break;
            }
            tot += dif[pos];
            if (tot >= mid){
                temp++;
                tot = 0;
            }else{
                continue;                
            }
        }
        if(temp<k+1){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << l << endl;
    return 0;
}