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
    ll m;
    cin>>m;
    vector<ll>d(m);
    rep(i,0,m)cin>>d[i];
    ll cnt = 0;
    ll tot = accumulate(all(d),0LL);
    ll h = (tot+1)/2;
    rep(i,0,m){
        ll dd = d[i];
        while(dd){
            dd--;
            cnt++;
            if (cnt==h){
                cout << i+1 << endl;
                cout << d[i]-dd << endl;
            }
        }
    }
    return 0;
}