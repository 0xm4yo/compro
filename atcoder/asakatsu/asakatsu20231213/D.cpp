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
    ll n,x,m;
    cin>>n>>x>>m;
    deque<ll> q;
    ll pnt = -2;
    vector<ll> v(m,-1);
    ll a = x;
    while(1){
        if (v[a]!=-1){
            pnt = a;
            break;
        }
        v[a] = a;
        q.push_back(a);
        a = (a*a)%m;
    }
    ll ans = 0;
    while(!q.empty() && n>0){
        ll now = q.front();
        if (now==pnt){
            ll sz = q.size();
            ll rem = n%sz;
            rep(i,0,rem) ans += q[i];
            ll tot = 0;
            rep(i,0,sz) tot += q[i];
            ans += tot * (n/sz);
            n = 0;
        }else{
            ans += now;
            q.pop_front();
            n--;
        }       
    }
    cout << ans << endl;

    return 0;
}