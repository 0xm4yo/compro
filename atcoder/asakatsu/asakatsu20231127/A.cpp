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
    ll x,y;
    cin>>x>>y;
    vector<ll>arr1 = {1,3,5,7,8,10,12}, arr2 = {4,6,9,11}, arr3 = {12};
    ll gx = 0, gy = -1;
    for (auto a: arr1){
        if (a == x) gx=1;
        if (a == y) gy=1;
    }
    for (auto a: arr2){
        if (a == x) gx=2;
        if (a == y) gy=2;       
    }
    for (auto a: arr3){
        if (a == x) gx=3;
        if (a == y) gy=3;       
    }    
    YesNo(gx==gy)

    return 0;
}