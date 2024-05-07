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
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    vector<ll>od,ev;
    for (auto x: a){
        if (x%2){
            od.push_back(x);
        }else{
            ev.push_back(x);
        }
    }
    ll ans = -1;
    sort(all(od));
    reverse(all(od));
    sort(all(ev));
    reverse(all(ev));
    if (od.size()>=2){
        chmax(ans, od[0]+od[1]);
    }
    if (ev.size()>=2){
        chmax(ans, ev[0]+ev[1]);
    }
    cout << ans << endl;
    return 0;
}