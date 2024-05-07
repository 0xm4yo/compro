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
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    vector<ll> arr(n+1);
    rrep(i,n,1){
        ll bit = a[i-1];
        ll tot = 0;
        for (int j=(n/i)*i;j>0;j-=i){
            tot ^= arr[j];
        }
        if (tot!=bit) arr[i]^=1;
    }
    bool flag = true;
    rrep(i,n,1){
        ll bit = a[i-1];
        ll tot = 0;
        for (int j=(n/i)*i;j>0;j-=i){
            tot ^= arr[j];
        }
        if (tot!=bit)flag = false;
    }
    if (!flag){
        cout << -1 << endl;
        return 0;
    }
    vector<ll> temp;
    rep(i,1,n+1){
        if (arr[i]) temp.push_back(i);
    }
    cout << temp.size() << endl;
    for (auto y: temp) cout << y << endl;
    return 0;
}