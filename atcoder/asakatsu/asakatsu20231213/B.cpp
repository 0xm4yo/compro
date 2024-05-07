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
    ll a,b;
    cin>>a>>b;
    if (a==b){
        cout << 0 << endl;
        return 0;
    }
    ll cnt = 0;
    while(1){
        if (a==0 || b==0)break;
        if (a>b) swap(a,b);
        if (a==b) break;
        cnt += b/a;
        b %= a;
    }
    cout << cnt-1 << endl;
    return 0;
}