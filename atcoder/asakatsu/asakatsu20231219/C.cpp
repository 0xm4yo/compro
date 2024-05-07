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
    ll l,n1,n2;
    cin>>l>>n1>>n2;
    deque<pair<ll,ll>>arr1={{0,0}}, arr2={{0,0}};
    rep(i,0,n1){
        ll v,l;
        cin>>v>>l;
        ll lt = arr1.back().second;
        arr1.push_back({v,lt+l});
    }
    rep(i,0,n2){
        ll v,l;
        cin>>v>>l;
        ll lt = arr2.back().second;
        arr2.push_back({v,lt+l});
    }
    
    ll pos = 0;
    ll ans = 0;
    arr1.pop_front();
    arr2.pop_front();
    while(!arr1.empty()&&!arr2.empty()){
        if (arr1.front().second > arr2.front().second) swap(arr1,arr2);
        if (arr1.front().first == arr2.front().first){
            ans += arr1.front().second - pos;
        }
        pos = arr1.front().second;
        arr1.pop_front();
    }
    cout << ans << endl;
    return 0;
}