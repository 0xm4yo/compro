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
    vector<ll>t(n),y(n);
    
    rep(i,0,n)cin>>t[i]>>y[i];
    priority_queue<ll>hq;
    
    ll rem = k;
    ll now = 0;
    ll ans = -INF;

    rrep(i,n-1,0){
        if (rem<0) break;
        if (t[i]==1){
            rem--;
            chmax(ans, y[i]+now);
            if (hq.size()>=rem){
                ll temp = hq.top(); hq.pop();
                now += temp;
            }    
        }else{
            if (y[i]<0){
                if (rem){
                    if (hq.size()<rem){
                        hq.push(y[i]);
                    }else{
                        ll temp = hq.top();
                        if (temp>y[i]){
                            hq.pop();
                            now += temp;
                            hq.push(y[i]);
                        }else{
                            now += y[i];
                        }
                    }
                }else{
                    now += y[i];
                }
            }else{
                now += y[i];
            }
        }
    }
    if (rem>=0) chmax(ans, now);
    cout << ans << endl;
    return 0;
}