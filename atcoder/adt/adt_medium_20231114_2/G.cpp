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
    ll l,q;
    cin>>l>>q;
    set<ll>arr;
    arr.insert(0);
    arr.insert(l);
    while(q){
        q--;
        ll c,x;
        cin>>c>>x;
        if (c==1){
            arr.insert(x);
        }else{
            auto itr = arr.lower_bound(x);
            ll r = *itr;
            itr--;
            ll l = *itr;
            cout << r - l << endl; 
        }
    }
    return 0;
}