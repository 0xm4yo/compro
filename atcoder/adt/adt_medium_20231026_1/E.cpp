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
    vector<ll>a(3*n), cnt(n);
    vector<pair<ll,ll>> pos;
    rep(i,0,3*n)cin>>a[i];
    rep(i,0,3*n){
        cnt[a[i]-1]++;
        if (cnt[a[i]-1]==2) pos.push_back({i, a[i]});
    }
    sort(all(pos));
    for (auto [p,num]: pos){
        cout << num << endl;
    }
    
    return 0;
}