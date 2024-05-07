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
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    ll now = 0;
    ll cnt = 0;
    ll cir = -1;
    ll st = -1;
    ll init = -1;
    vector<ll>v(n,-1);
    vector<ll>cum = {0};
    while(1){
        if (v[now]!=-1){
            cir = cnt - v[now] + 1;
            st = now;
            init = v[now]-1;
            break;
        }
        cnt++;
        cum.push_back(cum.back()+a[now]);
        v[now] = cnt;
        now = cum.back()%n;
    }
    ll tot = cum[cnt] - cum[init];
    ll ans = 0;
    ans += cum[min(init,k)];
    if (k>init){
        ans += (k-init)/cir * tot;
        ll rem = (k-init)%cir;
        now = st;
        while(rem){
            rem--;
            ans += a[now];
            now = ans%n;
        }
    }
    

    cout << ans << endl;

    
    return 0;
}